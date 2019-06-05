#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//struct to store each positions value and their immediate children
struct Node {
    int data;
    struct Node *left, *right;
};

//make a new node that's the size of a node in memory
//then initailize it's data to be the passed in value
//and make it have no immediate successors
struct Node *newNode(int val) { 
   struct Node *tempNode = (struct Node*) malloc(sizeof(struct Node)); 
   tempNode->data = val;
   tempNode->right = NULL;
   tempNode->left = NULL;
}

//searches the tree recurssively comparing the given value to the ones
struct Node *searchTree(struct Node* root, int val){

   if(root->data == val){
      cout << val << " is in the tree" << endl;
      return root;
   }
   // used to fix tree searching functionality
   // cout << "searching for " << val << " at " << root->data << endl;

   if(root->data > val){
      return searchTree(root->left, val);
   }
   else if (root->data < val){
      return searchTree(root->right, val);
   }//this doesnt work to correctly catch if a value is not in the list
   else {
      cout << "value not in list" << endl;
      return root; 
   }
}
//inserts the value into it's correct respective spot, then adjusts all other values in the list
//until a NULL node is found to insert furthest down node into
struct Node* insert(struct Node* node, int val){

   if(node == NULL)
      return newNode(val);
   if(val < node->data){
      node->left = insert(node->left, val);
   }
   else if (val > node->data) {
      node->right = insert(node->right, val);
   }

   return node;
}
//inorder traversal
void traversal(struct Node *root){
   if(root != NULL){
      traversal(root->left);
      cout << root->data << endl;
      traversal(root->right);
   }
}

struct Node* deleteNode(struct Node* root, int val){

   //checks for us not having a tree to search
   if(root == NULL) return root;

   //walk through the tree similar to the search function until it finds the appropriate value
   if(val < root->data) {
      root->left = deleteNode(root->left, val);
   }
   else if(val > root->data) {
      root->right = deleteNode(root->right, val);
   }
   else {//deletes the value then replaces it with it's successor if it's left or right 
         //branch respectively has no immediate successor
      if(root->left == NULL) {
         struct Node* temp = root->right;
         delete(root);
         return temp;
      }
      else if(root->right == NULL) {
         struct Node* temp = root->left;
         delete(root);
         return temp;
      }
      //moves down the right side of the tree shift their values up successively
      //not sure if this works for all values
      root->data = root->right->data;

      root->right = deleteNode(root->right, root->data);
   }
   return root;
}

int main(void){
   struct Node* root = NULL;

   root = insert(root, 100);
   insert(root, 10);
   insert(root, 1);
   insert(root, 102);
   insert(root, 122);
   insert(root, 22);
   insert(root, 32);
   insert(root, 52);

   traversal(root);


   searchTree(root, 22);

   cout << "deleting 22, 122, and 1" << endl;
   deleteNode(root, 22);
   deleteNode(root, 122);
   deleteNode(root, 1);
   deleteNode(root, 102);

   insert(root, 7);
   insert(root, 54);
   insert(root, 786);

   searchTree(root, 786);


   traversal(root);
}