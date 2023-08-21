#include <iostream>
using namespace std;

class QuickSortLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }
    };

    Node *head = NULL;

public:
    void addNode(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);

            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node *newNode = new Node(data);
        curr->next = newNode;
    }

    void printList(Node *n)
    {
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
    }

    // Initiate the first and the last node without breaking any links in the whole linked list.
    Node *partitionLast(Node *start, Node *end)
    {
        if (start == end || start == NULL || end == NULL)
            return start;

        Node *pivot_prev = start;
        Node *curr = start;
        int pivot = end->data;

        // Iterate till pen-ultimate node, since the last node is the PIVOT
        while (start != end)
        {
            if (start->data < pivot)
            {
                pivot_prev = curr;
                int temp = curr->data;
                curr->data = start->data;
                start->data = temp;
                curr = curr->next;
            }
            start = start->next;
        }

        // swap whichever is following suitable index and pivot
        int temp = curr->data;
        curr->data = pivot;
        end->data = temp;

        return pivot_prev;
    }

    void sort(Node *start, Node *end)
    {
        if (start == NULL || start == end || start == end->next)
            return;

        // split list and partition recurse
        Node *pivot_prev = partitionLast(start, end);
        sort(start, pivot_prev);

        // If PIVOT = START, we pick from next of PIVOT.
        if (pivot_prev != NULL && pivot_prev == start)
        {
            sort(pivot_prev->next, end);
        }

        // If PIVOT is still in between the list, start from next to pivot since we have pivot_prev, so we move two nodes.
        else if (pivot_prev != NULL && pivot_prev->next != NULL)
        {
            sort(pivot_prev->next->next, end);
        }
    }

    void execute()
    {
        cout << "Test 1";
        addNode(10);
        addNode(1);
        addNode(2);
        addNode(8);
        addNode(25);
        addNode(5);
        addNode(18);

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        cout << "Linked List before sorting" << endl;
        printList(head);
        sort(head, tail);
        cout << "\nLinked List after sorting" << endl;
        printList(head);
    }
};

// Main Driver Code
int main()
{
    QuickSortLinkedList list;
    list.execute();
    return 0;
}