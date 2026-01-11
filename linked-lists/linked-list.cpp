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

  bool isListEmpty() const
  {
    return head == nullptr;
  }

public:
  LinkedList()
  {
    head = nullptr;
  };

  ~LinkedList()
  {
    /**
     * The annotation ~ClassName() {...} is called a destructor
     *
     * As the name suggests, much like how a constructor executes when an instance of the class is created
     * The destructor function runs when that instance is deleted, acting as clean up of memory
     *
     * WHY:
     * The reason a destructor is important in the case of our linked list is illustrated in the following example
     *
     * EXAMPLE:
     * Consider the following code
     *
     * void test() {
     *  LinkedList list;
     *  list.insertAtBegining(10);
     *  list.insertAtEnd(20);
     * }
     *
     * once this function executes right before it ends the memory layout looks like this
     *
     * STACK:
     *  list: head -> 0x100 -> 0x200 -> null
     * HEAP:
     *  0x100 Node(10);
     *  0x200 Node(20);
     *
     * When test() ends stack gets cleaned up so the list object is destroyed and the head pointer is gone with it
     * But the Nodes inside the heap still remain and are uncreachable since the pointers are gone
     *
     * STACK:
     *  EMPTY
     * HEAP:
     *  0x100 Node(10);
     *  0x200 Node(20);
     *
     * RESULT: This eventually results in memory leak ()
     */

    clearList();
  }

  void printList()
  {
    if (isListEmpty())
      return;

    Node *current = head; // Pointer to the head node

    // While the reference current node points to is not null
    while (current != nullptr)
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

  void deleteAtBegining()
  {
    deleteAtPosition(0);
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

    deleteAtPosition(getSize() - 1);
  }

  void insertAtPosition(int value, int position)
  {
    /**
     *
     * The following mock data follows this pattern:
     *    Node Pointer: <value, Next node pointer>
     *
     * DATA:
     * head -> 0x100: <10, 0x200>
     *         0x200: <20, 0x300>
     *         0x300: <30, 0x400>
     *         0x400: <40, null>
     *
     * putting them in a linked list will result in the following visualization:
     * LIST: [0x100 -> 0x200 -> 0x300 -> 0x400 -> null]
     *
     * Assuming the list starts at position zero
     * We'll try inserting at position 2 (after 0x200)
     *
     * The operation will result in the following list
     * RESULT: [0x100 -> 0x200 -> 0x500 -> 0x300 -> 0x400 -> null]
     *
     */

    if (position == 0 || isListEmpty())
    {
      insertAtBegining(value);
      return;
    }

    if (position == -1)
    {
      insertAtEnd(value);
      return;
    }

    Node *current = head;

    for (int i = 0; i < position - 1; i++)
    {
      if (current->next != nullptr)
      {
        current = current->next;
      }
      else
      {
        // We reached the end of the list
        // Insert at the end
        insertAtEnd(value);
        return;
      }
    }

    Node *newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
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

  int getAt(int position) const
  {
    if (isListEmpty())
      return -1;

    Node *current = head;

    for (int i = 0; i < position; i++)
    {
      if (current->next == nullptr)
      {
        cout << "Position exceeds list size" << endl;
        return -1;
      }

      current = current->next;
    }

    return current->value;
  }

  void clearList()
  {
    if (isListEmpty())
      return;

    Node *current = head;

    while (current->next != nullptr)
    {
      Node *temp = current;
      current = current->next;

      delete temp;
    }

    // delete last node
    delete current;

    // reset head to null
    head = nullptr;
  }

  int getFirst() const
  {
    if (isListEmpty())
      return -1;

    return head->value;
  }

  int getLast() const
  {
    if (isListEmpty())
      return -1;

    Node *current = head;

    while (current->next != nullptr)
    {
      current = current->next;
    }

    return current->value;
  }

  void deleteAtPosition(int position)
  /**
   *
   * ACCESSING THE PREVIOUS NODE IN A SINGLY LINKED LIST
   *
   * Since we're implementing a singly linked list
   * Nodes don't have access to their previous node
   * The way we access the previous node is by maintaining two pointers that traverse the list together.
   *
   * PATTERN:
   * Node* current = head;
   * Node* previous = nullptr;
   *
   * // During traversal:
   * previous = current;      // Move previous to where current is
   * current = current->next; // Move current one step forward
   *
   * EXAMPLE:
   * Consider deleting the node at position 2 (value 30) from this list:
   *
   * head -> 0x100: <10, 0x200> -> 0x200: <20, 0x300> -> 0x300: <30, 0x400> -> 0x400: <40, null>
   *
   * Initial state (position 0):
   *   previous: nullptr
   *   current:  0x100 (value: 10)
   *
   * After first iteration (position 1):
   *   previous: 0x100 (value: 10)  ← previous = current (was 0x100)
   *   current:  0x200 (value: 20)  ← current = current->next (moved to 0x200)
   *
   * After second iteration (position 2):
   *   previous: 0x200 (value: 20)  ← previous = current (was 0x200)
   *   current:  0x300 (value: 30)  ← current = current->next (moved to 0x300)
   *
   * Now we can delete current (0x300) and reconnect the list:
   *   previous->next = current->next;  // 0x200's next now points to 0x400
   *   delete current;                   // Free 0x300
   *
   * RESULT: [0x100 -> 0x200 -> 0x400 -> null]
   *
   */

  {
    if (isListEmpty())
      return;

    if (position == 0)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < position; i++)
    {
      if (current->next == nullptr)
      {
        cout << "Position exceeds list size" << endl;
        return;
      }

      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
  }

  void deleteByValue(int value)
  {
    if (isListEmpty())
      return;

    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr && current->value != value)
    {
      previous = current;
      current = current->next;
    }

    if (current == nullptr || current->value != value)
    {
      cout << "Value not found" << endl;
      return;
    }

    if (current == head)
    {
      head = current->next;
      delete current;
      return;
    }

    previous->next = current->next;
    delete current;
  }

  // void reverse() {}
};

int main()
{
  cout << "Linked list" << endl;
  return 0;
};
