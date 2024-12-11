#include <iostream>
using namespace std;
// Create Tree Binary by class && Function deleting (Find Minimum and Maximum)  
class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {

    private:
    // Recursive function to search within the BST
    Node* Search(Node* r, int key) {
        if (r == NULL || r->data == key) {
            return r;
        } else if (key < r->data) {
            return Search(r->left, key);
        } else {
            return Search(r->right, key);
        }
    }

public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* Insert(Node* perNode, int item) {
        if (perNode == NULL) { // If root is empty
            Node* newNode = new Node(item);
            perNode = newNode;
        } else if (item < perNode->data) {
            perNode->left = Insert(perNode->left, item);
        } else {
            perNode->right = Insert(perNode->right, item);
        }
        return perNode;
    }

    void Insert(int item) {
        root = Insert(root, item); // Pass the tree root to insert the item
    }

    // Function Preorder root->left->right
    void Preorder(Node* p) {
        if (p == NULL) {
            return;
        }
        cout << p->data << "\t";
        Preorder(p->left);
        Preorder(p->right);
    }

    // Function Inorder left->root->right
    void Inorder(Node* i) {
        if (i == NULL) {
            return;
        }
        Inorder(i->left);
        cout << i->data << "\t"; // root
        Inorder(i->right);
    }

    // Function Postorder left->right->root
    void Postorder(Node* s) {
        if (s == NULL) {
            return;
        }
        Postorder(s->left);
        Postorder(s->right);
        cout << s->data << "\t"; // root
    }

    // Search function to search for a key in the tree
    bool Search(int key) {
        Node* result = Search(root, key);
        return (result != NULL);
    }

    // Function find main (All Minimum values ​​are less than root)
    Node* Findmain(Node* r)
    {
        if(r == NULL)
             return NULL;
           else if(r->left == NULL){
             return r;
           }else{
           return Findmain(r->left);
           }
    }

    // Function find main (All Findmax values ​​are greater than the root)
    Node* Findmax(Node* r)
    {
        if(r == NULL)
             return NULL;
           else if(r->right == NULL){
             return r;
           }else{
           return Findmax(r->right);
           }
    }
// Deletion possibilities
// 1. The node to be deleted is a leaf node.
// 2. The node to be deleted has one child.
// 3. The node to be deleted has two children.
// In the case of deletion, we take the smallest number from the left or the largest number from the right
// The Item in left(Pre) and in right(succ)

    //Function Delete Items 
    Node* Delete(Node* r, int key)
    {
        if(r == NULL)
         return NULL;
         if(key < r->data)
         r->left = Delete(r->left, key);
        else if(key > r->data)
        r->right = Delete(r->right, key);
        else
        {
        // 1. The node to be deleted is a leaf node.
           if(r->left == NULL && r->right == NULL)
            r= NULL;
        // 2. The node to be deleted has one child.(in left or right)
        else if(r->left != NULL && r->right == NULL) // If the item is on the left
        { r->data = r->left->data;
        delete r->left;
        r->left=NULL;
        }
        // If the item is on the right
        else if(r->left == NULL && r->right != NULL) {
          r->data = r->right->data;
           delete r->right;
          r->right=NULL;
        }//3. The node to be deleted has two children.
        else{
            Node* max = Findmax(r->left);
            r->data = max->data;
            r->left = Delete(r->left, max->data);
        }
       
    }
      return r;
    }

};

int main() {
    // Insert (45, 15, 79, 90, 10, 55, 12, 20, 50)
    BST obTree; // Create object
    obTree.Insert(45);
    obTree.Insert(15);
    obTree.Insert(79);
    obTree.Insert(90);
    obTree.Insert(10);
    obTree.Insert(55);
    obTree.Insert(12);
    obTree.Insert(20);
    obTree.Insert(50);

    cout << "Display the tree content \n";
    cout << "Preorder Traversal: \n";
    obTree.Preorder(obTree.root);
    cout << "\n......................................\n";
    cout << "Inorder Traversal: \n";
    obTree.Inorder(obTree.root);
    cout << "\n......................................\n";
    cout << "Postorder Traversal: \n";
    obTree.Postorder(obTree.root);

   cout <<"\n Find Minimum and Maximum values \n";
   cout <<"Find Minimum \n";
   Node *min = obTree.Findmain(obTree.root);
   if(min == 0) // NULL == 0
    cout<<"Not Items Exist\n";
    else
      cout<<"Maximum is: " <<min->data <<"\n";
      cout <<"Find Maximum: \n";
      Node* max = obTree.Findmax(obTree.root);
      if(max == 0)
       cout << "Find Maximum \n";
      else
       cout<< "Maximum is: " << max->data <<"\n";

       cout << "\nDelete Items \n";
       Node* result = obTree.Delete(obTree.root, 12);
       cout << "preorder After Delete 12: \n";
       obTree.Preorder(result);

       result = obTree.Delete(obTree.root, 15);
       cout << "\npreorder After Delete 15: \n";
       obTree.Preorder(result);

    return 0;
}

