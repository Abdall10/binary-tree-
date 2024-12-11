#include <iostream>
using namespace std;
// Create Tree Binary by class
class Node{
    public:
    int data;
    Node *left, *right;
    
    Node(int value){
        data=value;
        left = right = NULL;
    }    
};
// Create Tree Binary 
class BST {
    public:
    Node* root;

    BST()
    {
        root = NULL;
    }
   Node* Insert(Node* perNode, int item)
   {
    if(perNode == NULL) // if root empty
    {
        Node* newNode= new Node(item);
        perNode = newNode;
    }
    
    else if (item < perNode->data)    
      perNode->left =  Insert(perNode->left, item);
    else
     perNode->right =  Insert(perNode->right,item);

     return perNode;
   }

   // function preorder root->left->right
   void Preorder(Node* p){ 
    if(p == NULL){
        return;
    }
        cout<<p->data<<"\t";
        Preorder(p->left);
        Preorder(p->right);
   }

   // function Inorder left->root->right
   void Inorder(Node* i){ 
    if(i == NULL){
        return;
    }
        Inorder(i->left);
        cout<<i->data<<"\t"; // root
        Inorder(i->right);
   }

      // function Inorder left->right->root
   void Postorder(Node* s){ 
    if(s == NULL){
        return;
   }
        Postorder(s->left);
        Postorder(s->right);
        cout<<s->data<<"\t"; // root 
    }

   void Insert(int item){
    root = Insert(root, item); // Pass the tree empty to insert and Then it returns to its last value
   }
};




int main(){
    // Insert (45, 15, 79, 90, 10, 55, 12, 20, 50)
    BST obTree; // create object
    obTree.Insert(45);
    obTree.Insert(15);
    obTree.Insert(79);
    obTree.Insert(90);
    obTree.Insert(10);
    obTree.Insert(55);
    obTree.Insert(12);
    obTree.Insert(20);
    obTree.Insert(50);
    cout<<"Display the tree countent \n";
    cout << "Preorder Traversal: \n";
    obTree.Preorder(obTree.root);
    cout << "\n......................................\n";
    cout << "Inorder Traversal: \n";
    obTree.Inorder(obTree.root);
    cout << "\n......................................\n";
    cout << "Postorder Traversal: \n";
    obTree.Postorder(obTree.root);




    return 0;
}