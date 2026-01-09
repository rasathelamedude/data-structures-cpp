#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node *previous;

  Node(int value)
  {
    this->value = value;
    next = nullptr;
    previous = nullptr;
  }
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

  bool isListEmpty()
  {
    return head == nullptr;
  }

public:
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void readList()
  {
    if (isListEmpty())
    {
      cout << "List is empty" << endl;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
      cout << current->value << endl;
      current = current->next;
    }
  }
};

int main()
{
  cout << "Doubly linked list" << endl;
  return 0;
}