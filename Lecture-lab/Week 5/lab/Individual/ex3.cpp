#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
};

// Create a new node
Node* newNode(const string& data)
{
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Inorder traversal
void traverseInOrder(Node* temp)
{
    if (temp != nullptr)
    {
        traverseInOrder(temp->left);
        cout << temp->data << " ";
        traverseInOrder(temp->right);
    }
}

// Preorder traversal
void traversePreOrder(Node* temp)
{
    if (temp != nullptr)
    {
        cout << temp->data << " ";
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Postorder traversal
void traversePostOrder(Node* temp)
{
    if (temp != nullptr)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << temp->data << " ";
    }
}

int main()
{
    Node* node = newNode("A");

    // Left nodes
    node->left = newNode("B");
    node->left->left = newNode("D");
    node->left->right = newNode("E");
    node->left->left->left = newNode("H");
    node->left->left->right = newNode("I");

    // Right nodes
    node->right = newNode("C");
    node->right->left = newNode("F");
    node->right->right = newNode("G");

    cout << "Inorder traversal: ";
    traverseInOrder(node);
    cout << endl;

    cout << "Preorder traversal: ";
    traversePreOrder(node);
    cout << endl;

    cout << "Postorder traversal: ";
    traversePostOrder(node);
    cout << endl;

    // Deallocate memory
    delete node->left->left->right;
    delete node->left->left->left;
    delete node->left->right;
    delete node->left;
    delete node->right->right;
    delete node->right->left;
    delete node->right;
    delete node;

    return 0;
}
