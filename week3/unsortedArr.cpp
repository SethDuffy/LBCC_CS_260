#include "unsortedArr.h"
#include <iostream>

unsortedArr::unsortedArr() {
    length = 0;
}
int unsortedArr::getLength(){
    return length;
}
void unsortedArr::insert(int val){
    if(full()) return;

    values[length] = val;
    ++length;
}
//max array amount
bool unsortedArr::full() const {
    return (length >= 98);
}

void unsortedArr::removeAll() {
    length = 0;
}
//used to move
void unsortedArr::remove(int val) {
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

void unsortedArr::displayArr() {
    for(int i = 0; i < length; i++){
        std::cout << values[i];
    }
    std::cout << std::endl;
}
void unsortedArr::inList(int val) {
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
