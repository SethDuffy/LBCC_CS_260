ents from the list.
void ArrayList::MakeEmpty( )
{
    delete [] array;
    nelts = 0;
    ArraySize = 0;
    array = NULL;
}
// Tests to see if there are no elements in the array.
bool ArrayList::isEmpty( )
{
    return nelts == 0;
}
// Return the index of the first occurrance of a specified list element.  Returns -1 if not found.
int ArrayList::Find( double y )
{
    for( int i = 0; i < nelts; i++ ) {
        if( array[i] == y ) {

            // The user is considering the first element to be at position 1.
            return i +1;
        }
    }
    return -1;
}
// Insert the specied number in the list position.
void ArrayList::Insert( double y, int position )
{
    // Abort the program if a bad position is specified.
    assert( position >= 1 && position <= nelts + 1 );

    // Note the array position.  Recall that lists are numbered starting with 1.
    int ia = position - 1;

    // Make sure there is space in the array for a new element.
    MakeSpace( );

    // If we are adding a new element to the list, open up space if necessary.
    if( ia < nelts ) {
        memmove( &array[ia + 1], &array[ia], (nelts - ia) * sizeof(double ) );
    }
    array[ia] = y;
    nelts++;
}
// Display the elements of the list.
void ArrayList::PrintList( )
{
    // Display the list.
    for( int i = 0; i < nelts; i++ ) {
        cout << i + 1<< ". " << array[i] << endl;
    }
}
void ArrayList::MakeSpace( )
{
    // If there is space for another array element, return.
    if( nelts < ArraySize ) return;

    // Create storage to make a larger array.
    double *tmp;
    tmp = new double[ArraySize + ArrayIncrement];

    // Note that exceptions now occur when new fails unless you tell the compiler otherwise.
    assert( tmp != NULL );

    // If the previous array was not empty, must copy its contents.
    if( nelts > 0 ) {
        memcpy( tmp, array, nelts * sizeof(double) );
        delete [] array;
    }
    ArraySize += ArrayIncrement;
    array = tmp;
}
__________________________________________________________________

testList.cpp

// To test the implementation of the ADT list using arrays.
#include 
#include "ArrayList.h"
using namespace std;

int main( )
{
    ArrayList aaa;
    
    // Initialize the list.
    cout << "Array size = " << aaa.listSize() << endl;
    
    // Insert a lot of stuff;
    aaa.Insert( 111, 1 );
    aaa.Insert( 222, 1 );
    
    aaa.PrintList( );
    cout << endl;
    
    aaa.Insert( 333, 3 );
    aaa.Insert( 444, 2 );
    aaa.Insert( 555, 1 );
    
    aaa.PrintList( );
}