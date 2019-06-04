#include <iostream>
#include "sortedArr.h"
int main() {
   sortedArr arr;

   arr.insert(1);
   arr.insert(3);
   arr.insert(6);
   arr.insert(7);
   arr.insert(4);
   arr.insert(5);
   arr.insert(2);


   arr.displayArr();
   arr.inList(2);
   arr.remove(2);
   arr.displayArr();
   arr.inList(2);
}