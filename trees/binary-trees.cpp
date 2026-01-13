#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *parent;
  Node *right_child;
  Node *left_child;

  Node(int value)
  {
    this->value = value;
    parent = nullptr;
    right_child = nullptr;
    left_child = nullptr;
  }
};

class BinaryTree
{
private:
  Node *root;

public:
  BinaryTree()
  {
    root = nullptr;
  }

  ~BinaryTree()
  {
    clearTree();
  }

  void clearTree()
  {
  }
};
