#include "sortedArr.h"
#include <iostream>

sortedArr::sortedArr() {
    length = 0;
}
int sortedArr::getLength(){
    return length;
}
void sortedArr::insert(int val) {
    if(full()) return;

    if(length == 0) {
        values[0] = val;
        length++;
    }
    else {
        int i = 0;
        while(values[i] >= val) {
            i++;
        }
        //shifts all values 1 to the "right"
        for(int j = length-1; j > i; j--) {
            values[j+1] = values[j]
        }
        values[]
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

void sortedArr::displayArr() {
    for(int i = 0; i < length; i++){
        std::cout << values[i] << std::endl;
    }
}
void sortedArr::inList(int val) {
    bool inside = false;
    int i = 0;
    while(!inside){
        if(values[i] == val) {
            inside = true;
            std::cout << val << " is in the list" << std::endl;
        }
        else if(i >= length) {
            inside = true;
            std::cout << val << " is not in the list" << std::endl;
        }
        i++;
    }
}
