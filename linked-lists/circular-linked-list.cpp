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

  int getSize() const
  {
    int size = 0;

    Node *current = head;

    while (current->next != head)
    {
      size++;
      current = current->next;
    }

    // Account for the last node
    return ++size;
  }

public:
  Node *head;
  Node *tail;

  CircularLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insertAtBeginning(int value)
  {
    Node *newNode = new Node(value);

    if (isEmpty())
    {
      head = newNode;
      tail = newNode;
      tail->next = head;
    }
    else
    {
      newNode->next = head;
      tail->next = newNode;
      head = newNode;
    }
  }

  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (isEmpty())
    {
      head = newNode;
      tail = newNode;
      tail->next = head;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
      tail->next = head;
    }
  }

  void insertAtPosition(int position, int value)
  {
    if (position == 0)
    {
      insertAtBeginning(value);
    }

    if (position == getSize())
    {
      insertAtEnd(value);
    }

    if (position > getSize())
    {
      cout << "Position exceeds list size" << endl;
    }

    Node *newNode = new Node(value);
    Node *current = head;

    for (int i = 0; i < position - 1; i++)
    {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }

  void deleteAtBeginning()
  {
    if (isEmpty())
      return;

    if (head == tail)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = head->next;
      tail->next = head;
    }
  }

  void deleteAtEnd()
  {
    if (isEmpty())
      return;

    if (head == tail)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      Node *current = head;

      while (current->next != tail)
      {
        current = current->next;
      }

      current->next = head;
      tail = current;
    }
  }

  void deleteAtPosition(int position)
  {
    if (position == 0)
    {
      deleteAtBeginning();
    }

    if (position == getSize() - 1)
    {
      deleteAtEnd();
    }

    if (position > getSize())
    {
      cout << "Position exceeds list size" << endl;
    }

    Node *current = head;

    for (int i = 0; i < position - 1; i++)
    {
      current = current->next;
    }

    current->next = current->next->next;
  }

  void printList() 
  {
    
  }

  void reverse() {}
};

int main()
{
  CircularLinkedList list;

  list.insertAtBeginning(10);
  list.insertAtBeginning(20);
  list.insertAtBeginning(30);

  list.insertAtPosition(1, 40);

  return 0;
}