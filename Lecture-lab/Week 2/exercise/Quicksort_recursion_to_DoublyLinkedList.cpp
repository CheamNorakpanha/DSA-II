#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* getNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = getNode(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

Node* partition(Node* first, Node* last) {
    int pivot = last->data;
    Node* i = first->prev;

    for (Node* j = first; j != last; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? first : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == nullptr) ? first : i->next;
    swap(i->data, last->data);
    return i;
}

void quickSort(Node* first, Node* last) {
    if (last != nullptr && first != last && first != last->next) {
        Node* pivot = partition(first, last);
        quickSort(first, pivot->prev);
        quickSort(pivot->next, last);
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.";
        return;
    }
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 2);
    insert(&head, 10);
    insert(&head, 3);

    cout << "Unsorted list: ";
    printList(head);

    Node* lastNode = head;
    while (lastNode->next)
        lastNode = lastNode->next;

    quickSort(head, lastNode);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
