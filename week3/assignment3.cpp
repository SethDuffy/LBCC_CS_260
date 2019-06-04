#include <iostream>
#include "unsortedArr.h"
#include "unsortedLL.h"

int main() {
   // unsortedArr arr;

   // arr.insert(1);
   // arr.insert(2);
   // arr.insert(3);
   // arr.insert(4);
   // arr.insert(5);
   // arr.insert(6);
   // arr.insert(7);

   // arr.displayArr();
   // arr.inList(2);
   // arr.remove(2);
   // arr.displayArr();
   // arr.inList(2);


   unsortedLL ll;

   ll.insert(1);
   ll.insert(2);
   ll.insert(3);
   ll.insert(4);
   ll.insert(5);
   ll.insert(6);
   ll.insert(7);
   ll.insert(8);
   ll.insert(9);


   ll.displayLL();
   ll.inList(3);
   ll.remove(3);
   ll.displayLL();
   ll.inList(3);
   

}