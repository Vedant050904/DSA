#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *next;
};

// Function Prototypes

void linkedListTraversal(Node *ptr);
// Case 1
Node* insertAtFirst(Node *head, int data);
// Case 2
Node* insertAtIndex(Node *head, int data, int index);
// Case 3
Node* insertAtEnd(Node *head, int data);
// Case 4
Node* insertAfterNode(Node *head, Node *prevNode, int data);

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

    cout << "Linked list before insertion\n";
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 33, 2);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, third, 45);
    cout << "\nLinked list after insertion\n";
    linkedListTraversal(head);

    return 0;
}

// Function Implementations

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1
Node* insertAtFirst(Node *head, int data)
{
    Node* ptr = new Node;
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
Node* insertAtIndex(Node *head, int data, int index)
{
    Node* ptr = new Node;
    Node* p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
Node* insertAtEnd(Node *head, int data)
{
    Node* ptr = new Node;
    ptr->data = data;
    Node * p = head;

    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
Node* insertAfterNode(Node *head, Node *prevNode, int data)
{
    Node* ptr = new Node;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}