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

  bool isListEmpty() const
  {
    return head == nullptr;
  }

public:
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void printList()
  {
    if (isListEmpty())
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
      cout << current->value << endl;
      current = current->next;
    }
  }

  int getSize() const
  {
    if (isListEmpty())
      return 0;

    int counter = 0;
    Node *current = head;

    while (current != nullptr)
    {
      counter++;
      current = current->next;
    }

    return counter;
  }

  void insertAtBeginning(int value)
  {
    /**
     * NOTE: "Node newNode" on the following line will result in an error becuase of type mismatch
     *
     * The new keyword creates a new object on the heap and 'returns its address'
     *
     * Assigning a pointer (address) to a full object (Node) will generate an error
     * Therefore the type Node* is used instead of Node
     *
     */
    Node *newNode = new Node(value);

    if (isListEmpty())
    {
      head = newNode;
      tail = newNode;
      return;
    }

    newNode->next = head;
    head->previous = newNode;
    head = newNode;
  }

  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (isListEmpty())
    {
      head = newNode;
      tail = newNode;
      return;
    }

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
  }

  void insertAtPosition(int value, int position)
  {
    if (position <= 0 || isListEmpty())
    {
      insertAtBeginning(value);
      return;
    }

    if (position == getSize() - 1)
    {
      insertAtEnd(value);
      return;
    }

    if (position >= getSize())
    {
      cout << "Position exceeds list size" << endl;
      return;
    }

    Node *newNode = new Node(value);
    Node *current = head;

    for (size_t i = 0; i < position; i++)
    {
      current = current->next;
    }

    newNode->next = current;
    newNode->previous = current->previous;

    current->previous->next = newNode;
    current->previous = newNode;
  }

  void deleteAtBeginning()
  {
    if (isListEmpty())
      return;

    Node *temp = head;

    if (head == tail)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = head->next;
      head->previous = nullptr;
    }

    delete temp;
  }

  void deleteAtEnd()
  {
    /**
     * EXAMPLE:
     * each of these addresses (e.g. 0x100) hold a node with a value and an address pointing to the node after it
     *
     * We want to get the node at address 0x200 (second last node)
     * Free and reclaim the memory of the node next to it (address 0x300)
     * Make the pointer pointing to 0x200's next null so it doesn't point to dead memory
     *
     * head
     *  ↓
     * 0x100: [10 | 0x200]
     * 0x200: [20 | 0x300]
     * 0x300: [30 | null]
     *
     */

    if (isListEmpty())
      return;

    Node *temp = tail;

    if (head == tail)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      tail = tail->previous;
      tail->next = nullptr;
    }

    delete temp;
  }

  void deleteAtPosition(int position)
  {
    if (isListEmpty())
      return;

    if (position <= 0)
    {
      deleteAtBeginning();
      return;
    }

    if (position == getSize() - 1)
    {
      deleteAtEnd();
      return;
    }

    if (position >= getSize())
    {
      cout << "Position exceeds list size" << endl;
      return;
    }

    Node *current = head;

    for (size_t i = 0; i < position; i++)
    {
      current = current->next;
    }

    current->previous->next = current->next;
    current->next->previous = current->previous;

    delete current;
  }
};

int main()
{
  cout << "Doubly linked list" << endl;
  return 0;
}