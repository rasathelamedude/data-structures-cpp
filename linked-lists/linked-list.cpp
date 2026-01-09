#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next; // 0x100->next
};

class LinkedList {
private:
  Node head;

public:
  void readList() {
    Node current = head;

    while (current->next) {}
  };
};