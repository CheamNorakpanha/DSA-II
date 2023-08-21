// Binary Tree in C++
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// New node creation
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
    if(temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}

// Traverse Preoder
void traversePreOder(struct node *temp)
{
    if(temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOder(temp->left);
        traversePreOder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
    if(temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

int main()
{
    struct node *root = newNode(2);

    // Left nodes
    root->left = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(11);

    // Right nodes
    root->right = newNode(5);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);

    cout << "Inorder traversal: ";
    traverseInOrder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    traversePreOder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    traversePostOrder(root);
    cout << endl;

}