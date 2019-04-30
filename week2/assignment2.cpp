#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int data;
    struct Node *next;
};

struct Node* top = NULL; 
void push(int val) {
   struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
   newNode->data = val; 
   newNode->next = top; 
   top = newNode; 
}
void pop() {
   if(top==NULL)
      cout<<"No Items on stack"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
   }
}

void peek() {
   if(top==NULL)
      cout << "stack is empty" << endl;
   else {   
        cout << "The " << top->data << endl;
   }
   return;
}
int main(void){
   pop();
   peek();
   push(10);
   cout << "Pushed 10 on the stack" << endl;
   cout << "Peek value "; 
   peek(); 
   cout << endl << "Popping value" << endl;
   pop();
   cout << "Peeking" << endl;
   peek();
}