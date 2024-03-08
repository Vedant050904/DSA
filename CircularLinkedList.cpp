#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void linkedListTraversal(Node *head) {
  Node *current = head;
  do {
    cout << "Element: " << current->data << endl;
    current = current->next;
  } while (current != head);
}

int main() {
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

  // Link fourth and head nodes to make it circular
  fourth->data = 66;
  fourth->next = head;

  linkedListTraversal(head);

  return 0;
}