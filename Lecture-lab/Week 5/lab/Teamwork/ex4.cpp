#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *center;
    struct node *right;
};

// New node creation
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->center = NULL;
    node->right = NULL;
    return node;
}

// Traverse Inorder
void traverseInOrder(struct node* temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->center);
        traverseInOrder(temp->right);
    }
}

// Traverse Preorder
void traversePreOrder(struct node* temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->center);
        traversePreOrder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node* temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->center);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

int main()
{
    struct node* root = newNode(1);

    // Left nodes
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->center = newNode(6);
    root->left->left->left = newNode(4);
    root->left->left->center = newNode(5);
    
    // Center nodes
    root->center = newNode(7);

    // Right nodes
    root->right = newNode(8);
    root->right->center = newNode(9);
    root->right->right = newNode(12);
    root->right->center->center = newNode(10);
    root->right->center->right = newNode(11);
    

    cout << "Inorder traversal: ";
    traverseInOrder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    traversePreOrder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    traversePostOrder(root);
    cout << endl;

    return 0;
}
