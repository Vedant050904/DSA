#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function Prototypes

void linkedListTraversal(Node *ptr);
// Case 1: Deleting the first element from the linked list
Node * deleteFirst(Node * head);
// Case 2: Deleting the element at a given index from the linked list
Node * deleteAtIndex(Node * head, int index);
// Case 3: Deleting the last element
Node * deleteAtLast(Node * head);
// Case 4: Deleting the element with a given value from the linked list
Node * deleteByValue(Node * head, int value);

// Main Function
int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    cout << "\nLinked list before deletion\n";
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    cout << "\nLinked list after deletion\n";
    linkedListTraversal(head);

    return 0;
}

// Function Implementations

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element:" << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
Node * deleteFirst(Node * head)
{
    Node * ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
Node * deleteAtIndex(Node * head, int index)
{
    Node *p = head;
    Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return head;
}

// Case 3: Deleting the last element
Node * deleteAtLast(Node * head)
{
    Node *p = head;
    Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    delete q;
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
Node * deleteByValue(Node * head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}