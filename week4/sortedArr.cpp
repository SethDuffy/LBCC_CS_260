#include "sortedArr.h"
#include <iostream>

sortedArr::sortedArr() {
    length = 0;
}
int sortedArr::getLength(){
    return length;
}
void sortedArr::displayArr() {
    for(int i = 0; i < length; i++){
        std::cout << values[i] << std::endl;
    }
}
void sortedArr::insert(int val) {
    if(full()) return;

    if(length == 0) {
        values[0] = val;
        length++;
    }
    else {
        int i = 0;
        int temp = val;
        while(values[i] <= val && values[i] != 0){
            i++;
        }
        //std::cout << "values[i]= " << values[i] << std::endl << "val= " << val << std::endl << "i= " << i << std::endl;
        //shifts all values 1 to the "right"
        for(int j = length; j >= i; j--) {
            values[j+1] = values[j];
        }
        val = temp;
        values[i] = val;
        length++;
    }
}
//max array amount
bool sortedArr::full() const {
    return (length >= 98);
}

void sortedArr::removeAll() {
    length = 0;
}
//used to move
void sortedArr::remove(int val) {
    for( int i = 0; i < length; i++){
        if(values[i] == val){
            //shift all values after down 1
            for(int j = i+1; j < length; j++){
                values[j-1] = values[j];
            }
            length--;
        }
    }
}
void sortedArr::inList(int val) {
    bool inside = false;
    int i = 0;

    int begin = 0, end = length, key = length/2;
    while(!inside){
        
        // assignment 4 binary search
        if(values[key] == val){
            std::cout << "The Value " << val << " is in the list" << std::endl;
            inside = true;
            return;
        }
        else if(values[key] > val){
            end = key;
            key = key/2;
        }
        else if(values[key] < val) {
            int temp = 0;
            // std::cout << "key= " << key << std::endl;
            // std::cout << "begin= " << begin << std::endl;
            // std::cout << "end= " << end << std::endl;
            begin = key;
            if((end-begin)/2 == 0) {
                temp = 1;
            }
            key += ((end-begin)/2);
            key += temp;
        }
        if ((end - begin) <= 1) {
            std::cout << val << " does not exist in the list" << std::endl;
            inside = true;
            return; 
        }


        // assignment 3 search funtion
        // if(values[i] == val) {
        //     inside = true;
        //     std::cout << val << " is in the list" << std::endl;
        // }
        // else if(i >= length) {
        //     inside = true;
        //     std::cout << val << " is not in the list" << std::endl;
        // }
        // i++;
    }
}


// shift function made to test my sanity/
// if I knew anything about anything
// void sortedArr::shift(){
//     int arr[11] = {5,6};
//     int i = 0;
//     int val = 4;
//     while(arr[i] <= val && arr[i] != 0){
//         i++;
//     }
//     // int temp = i;
//     // std::cout << temp << std::endl;
//     std::cout << i << std::endl;
    
//     //shifts all values 1 to the "right"
//     for(int j = 11; j >= i; j--) {
//         arr[j+1] = arr[j];
//     }
//     val = 4;
//     std::cout << "arr[i]= " << arr[i] << std::endl << "val= " << val << std::endl;
//     arr[i] = val;
//     for( int j = 0; j < 11; j++){
//         std::cout << "arr[i]= " << arr[j] << std::endl;
//     }
// }
