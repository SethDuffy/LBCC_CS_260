#include "nodeType.h"

class unsortedLL {
    public:
        unsortedLL();
        void removeAll();
        bool full() const;
        int getLength();
        void insert(int val);
        void remove(int val);
        void displayLL();
        void inList(int val);
    private:
        int length;

        //only for linked list
        nodeType* start;
};