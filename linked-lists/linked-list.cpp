#include <iostream>

using namespace std;

/**
 * NOTE: Objects are stored on <stack | heap>
 *
 * Stack is fast scoped memory
 * Heap is long-lived dynamic memory
 *
 * EXAMPLE:
 * The object (n) in the following example is stored on the stack
 * When the function finishes executing (n) is destroyed, you don't control it's lifetime
 *
 * NOTE: The new keyword is not used
 *
 * @fn foo() {
 *  Node n(10);
 * }
 *
 * EXAMPLE:
 * On the other hand the following line creates an object on the heap
 * You control its lifetime, meaning it lives there until you delete the object and reclaim the space
 *
 * @line
 * Node* n = new Node(10);
 *
 * NOTE: The new keyword is not just "create object" but rather "Allocate memory on the heap, construct an object there, and return its address"
 */

class Node
{
public:
  int value;
  Node *next; // 0x100

  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList
{
private:
  Node *head; // Head holds the memory address of a node that is head

  bool isListEmpty()
  {
    return head == nullptr;
  }

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

  void insertAtBegining(int value)
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
      return;
    }

    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (isListEmpty())
    {
      head = newNode;
      return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newNode;
  }

  void deleteAtBegining() {
    if (isListEmpty()) {
      return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void deleteAtEnd() {
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

    if (isListEmpty()) {
      return;
    }

    // If there is only one node
    if (head->next == nullptr) {
      delete head; // Free memory allocated to head
      head = nullptr; // Avoid pointing to dead/freed memory
      return;
    }

    Node* current = head;
    
    while(current->next->next != nullptr) {
      current = current->next;
    }

    delete current->next;
    current->next = nullptr;
  }
};