#include <iostream>
using namespace std;

// We used a "struct" called 'node', which represents a node in the linked list.
struct Node
{
    int data;
    Node* next;
};

// We defined the 'getTail' function in order to take a pointer to the head of a linked list and returns a pointer to the last node (tail) of the list.
// It returns the final node after going over the entire list in iterations. (in repeat)
Node* getTail(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current;
}

// The partition function takes the head and end nodes of a linked list, as well as pointers to newHead and newEnd nodes.
// It selects the last node (pivot) as the partition element and rearranges the nodes such that all the nodes with values less than the pivot are placed before it
// All the nodes with values greater than or equal to the pivot are placed after it. It returns the pivot node.
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd)
{
    Node* pivot = end;
    Node* prev = nullptr;
    Node* current = head;
    Node* tail = pivot;

    while (current != pivot)
    {
        if (current->data < pivot->data)
        {
            if (*newHead == nullptr)
                *newHead = current;

            prev = current;
            current = current->next;
        } 
        else 
        {
            if (prev)
                prev->next = current->next;

            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

// The quickSort function performs the actual sorting of the linked list using the quicksort algorithm.
Node* quickSort(Node* head, Node* end)
{
    if (head == nullptr || head == end)
        return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;
        newHead = quickSort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

// We defined 'printList' function to take the head of a linked list and prints the data values of all the nodes in the list.
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node();
    head->data = 5;

    Node* second = new Node();
    second->data = 8;
    head->next = second;

    Node* third = new Node();
    third->data = 2;
    second->next = third;

    Node* fourth = new Node();
    fourth->data = 10;
    third->next = fourth;

    Node* fifth = new Node();
    fifth->data = 3;
    fourth->next = fifth;
    fifth->next = nullptr;

    cout << "Unsorted Linked List: ";
    printList(head);

    // The 'getTail' function is called to obtain the tail node of the list.
    Node* tail = getTail(head);

    // The 'quickSort' function is called to sort the linked list.
    // The sorted list is assigned to the head pointer.
    head = quickSort(head, tail);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}

// ========================================>>> Code explanation <<<========================================
// The code starts by creating a new Node object and assigning it the value of 5.
// Next, it creates a new Node object and assigns the value of 8 to it.
// The next line sets head to be equal to second, which is the node immediately after head in the list.
// Then third is created and assigned the value of 2.
// Second is set to be equal to third, which moves second up one position in the list.
// Finally fourth is created with the value of 10, moving it up two positions in the list.
// Third is then set to be equal to fourth, which moves third up one position in the list again.
// Fifth is created and assigned 3, moving it down one position in the list.
// Finally tail is set to be equal to fifth, which returns head back where it started (at first).
// The code then prints out an unsorted linked list before sorting it using quickSort().
// The sorted linked list will look like this: Unsorted Linked List: 5 8 2 10 3
// The code prints the following: Unsorted Linked List: 5 8 2 10 3 Sorted Linked List: 2 10 3 5 8
// ========================================================================================================