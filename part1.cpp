#include <iostream>
using namespace std;
// Create Tree Binary by struct
struct Node {
   int data;
   Node* left;
   Node* right;
};
// function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// function to insert a new node with given key in BST
void display(Node* root){
    if( root == nullptr ) return;

    cout << root->data << endl;
    display(root->left);
    display(root->right);
}

int main(){

// Level 1 
 Node* root=createNode(1);
//Level 2 
 root->left= createNode(2);
 root->right= createNode(3);
// Level 3 
 root->left->left=createNode(4);
 root->left->right=createNode(5);
 root->right->left=createNode(6);
 root->right->right=createNode(7);

 //Level 4 
 root->left->right->left=createNode(10);
 root->right->right->left=createNode(15);

 display(root);
    return 0;
}