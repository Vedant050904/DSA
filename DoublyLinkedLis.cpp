#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* prev;
    Node* next;
};

void linkedListTraversalForward(Node* ptr);
void linkedListTraversalBackward(Node* ptr);

int main() 
{
    Node* head;
    Node* second;
    Node* third;
    Node* fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->prev = nullptr;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->prev = head;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->prev = second;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->prev = third;
    fourth->next = nullptr;

    cout << "\nMoving next.\n";
    linkedListTraversalForward(head);

    cout << "\nMoving Back.\n";
    linkedListTraversalBackward(fourth);

    return 0;
}

void linkedListTraversalForward(Node* ptr)
{
    while (ptr != nullptr) 
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void linkedListTraversalBackward(Node* ptr)
{
    while (ptr != nullptr) 
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->prev;
    }
}