#include "nodeType.h"

class unsortedLL {
    public:
        unsortedLL();
        int getLength();
        void insert(string name);
        void remove(string name);
        void displayLL();
        void inList(string name);
    private:
        int length;

        //only for linked list
        nodeType* start;
};