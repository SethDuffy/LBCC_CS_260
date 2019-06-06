#include "unsortedLL.h"
#include <iostream>

//constructor
unsortedLL::unsortedLL(){
    length = 0;
    start = NULL;
}
//inserts new node
void unsortedLL::insert(string name){
    nodeType* temp = new nodeType;
    temp->value = val;
    temp->next = start;
    start = temp;

    length++;
}

int unsortedLL::getLength() {
    return length;
}

void unsortedLL::displayLL() {
    nodeType* temp = start;
    while(temp != NULL){
        std::cout << temp->name << std::endl;
        temp = temp->next;
    }
}

void unsortedLL::remove(string name) {

    if(start != NULL){
        nodeType* temp = start;
        if(val == start->value){
            start = start->next;
            delete temp;
            length--;
        }
        else {
            while(temp->next != NULL && !(val ==((temp->next)->value))){
                temp = temp->next;
            }
            nodeType* target = temp->next;
            if(target != NULL) {
                temp->next = target->next;
                delete target;
                length--;
            }
            else {
                std::cout << val << " does not exist in the list" << std::endl;
            }
        }
    }
}

void unsortedLL::inList(string name) {
    if(start != NULL){
        nodeType* temp = start;
        if(val == start->value){
            std::cout << val << " is in the list" << std::endl;
        }
        else {
            while(temp != NULL){
                if(temp->value == val){
                    std::cout << val << " is in the list" << std::endl;
                }
                temp = temp->next;
            }
            if(temp == NULL) {
                std::cout << val << " is not in the list" << std::endl;
            }
        }
    }
}