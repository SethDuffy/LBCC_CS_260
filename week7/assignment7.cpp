#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::cin;
using std::endl;


const int TABLE_SIZE = 10;


class person {
    string name
};

int hash(string name) {
    int nameVal = 0;
    for(int i = 0; i < name.length(); i++){
        nameVal += int(name[i]);
    }
    return nameVal % TABLE_SIZE;
}


int main (void) {
    person people[TABLE_SIZE] = new person();
    return 0;
}



