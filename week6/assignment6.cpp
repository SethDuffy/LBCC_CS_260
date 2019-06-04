#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int val) { 
   struct Node *tempNode = (struct Node*) malloc(sizeof(struct Node)); 
   tempNode->data = val;
   tempNode->left = tempNode->right;
   tempNode->right = NULL;
}

struct Node *searchTree(struct Node* root, int val){

   if(root->data == val){
      cout << val << " is in the tree" << endl;
      return root;
   }
   if(root->data < val){
      return searchTree(root->left, val);
   }
   return searchTree(root->right, val);
}

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
      cout << "Root value: " << root->data << endl;
      traversal(root->right);
   }
}

struct Node* deleteNode(struct Node* root, int val){
   if(root == NULL) return root;

   //traverse the tree to find the value
   if(val < root->data) {
      root->left = deleteNode(root->left, val);
   }
   else if(val > root->data) {
      root->right = deleteNode(root->right, val);
   }
   else {
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

      struct Node* temp = root->right;
      while(temp != NULL && temp->left != NULL) {
         temp = temp->left;
      }
      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
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

   deleteNode(root, 22);
   searchTree(root, 22);
}