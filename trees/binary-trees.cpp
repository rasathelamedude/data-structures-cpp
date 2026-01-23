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

class BinarySearchTree
{
private:
  Node *root;

public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  ~BinarySearchTree()
  {
    clearTree();
  }

  Node* getRoot() {
    return root;
  }

  void clearTree()
  {
  }

  void traverseInOrder(Node *current)
  {
    if (current == nullptr)
    {
      return;
    }

    traverseInOrder(current->left_child);
    cout << current->value << " ";
    traverseInOrder(current->right_child);
  }

  void insert(int value)
  {
    if (root == nullptr)  
      root = new Node(value);
    else 
      insertRecursive(root, value);
  }

  Node* insertRecursive(Node* current, int value) {
    if (current == nullptr) {
      return new Node(value);
    }

    if (value < current->value) {
      current->left_child = insertRecursive(current->left_child, value);
      current->left_child->parent = current;
    } else {
      current->right_child = insertRecursive(current->right_child, value);
      current->right_child->parent = current;
    }

    return current;
  }
};

int main()
{
  BinarySearchTree bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);

  bst.traverseInOrder(bst.getRoot());

  return 0;
}