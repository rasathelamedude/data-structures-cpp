#include <iostream>

using namespace std;

/**
 *
 * A circular linked list is a linked list where the last node points back to the first node, creating a closed loop.
 *
 * EXAMPLE:
 * head -> 0x100: <10, 0x200> -> 0x200: <20, 0x300> -> 0x300: <30, 0x100>
 *
 * It is ideal for tasks like scheduling like round-robin scheduling in operating systems, where you want to store a list of tasks that need to be executed in a specific order. 
 * As well as in playlists, where you want to store a list of songs in a specific order.
 * And repeating sequences like Traffic lights (red -> yellow -> green). 
 *
 * Circular linked lists can be of both types (singly and doubly)
 * We'll only implement circular singly linked lists since doubly linked lists have already been implemented and the concepts are the same
 */

class Node
{
public:
  int value;
  Node *next;

  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
  }
};

class CircularLinkedList
{
private:
  bool isEmpty() const
  {
    return head == nullptr;
  }

public:
  Node *head;
  Node *tail;

  CircularLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insertAtBeginning(int value) {}

  void insertAtEnd(int value) {}

  void insertAtPosition(int position, int value) {}

  void deleteAtBeginning() {}

  void deleteAtEnd() {}

  void deleteAtPosition(int position) {}

  void printList() {}

  void reverse() {}
};

int main()
{
  cout << "Circular linked list" << endl;
  return 0;
}