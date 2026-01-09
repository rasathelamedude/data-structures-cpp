#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node* next; // 0x100
};

class LinkedList
{
private:
  Node *head; // Head holds the memory address of a node that is head

public:
  LinkedList()
  {
    head = nullptr;
  };

  void traverseList()
  {
    Node *current = head; // Pointer to the head node

    // While the reference current node points to is not null
    while (current->next != nullptr)
    {
      cout << current->value << endl;
      current = current->next;
    }; // current->next == (*current).next
  };
};