#include <iostream>
#include "unsortedLL.h"

using std::cout;
using std::endl;

const int TABLE_SIZE = 10;

int hashify(int val, int length) {
    return val % length;
}

bool checkTable(unsortedLL (&hash)[TABLE_SIZE], int val) {

    if(hash[hashify(val, TABLE_SIZE)].inList(val))
        return true;
}

void insertVal(unsortedLL (&hash)[TABLE_SIZE], int val){
    int key = hashify(val, TABLE_SIZE);
    if(checkTable(hash, val)) {
        cout << "err: " << val << " already in list" << endl;
        return;
    }
    hash[key].insert(val);
}




int main (void) {

    unsortedLL hash[TABLE_SIZE];


    insertVal(hash, 10);
    insertVal(hash, 20);
    insertVal(hash, 30);
    insertVal(hash, 40);
    insertVal(hash, 9);


    cout << "chekcing if values 40, 50, 9, 20 are in the table" << endl;
    cout << "40:" << checkTable(hash, 40) << endl;
    cout << "50:" << checkTable(hash, 50) << endl;
    cout << "9:" << checkTable(hash, 9) << endl;
    cout << "20:" << checkTable(hash, 20) << endl;

    return 0;
}



