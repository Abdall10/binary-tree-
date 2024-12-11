#include <iostream>
using namespace std;
// Create Tree Binary by class && Function Search in Tree Binary    
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

    int key;
    char choice;

    do {
        cout << "\nEnter a key to search: ";
        cin >> key;
        if (obTree.Search(key)) {
            cout << "Item is found\n";
        } else {
            cout << "Sorry, item is not found\n";
        }

        cout << "\nDo you want to search for another key? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the program. \n";

    return 0;
}
