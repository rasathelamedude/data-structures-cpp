#include <iostream>
#include <queue>
#include <Node.h>

using namespace std;

/**
 * 
 * Unlike arrays, linked lists, and queues which are linear.
 * Trees are a hierarchical data structure, which means nodes are not stored in  contiguous memory locations, the hierarchical structure is implemented logically via node pointers.
 *  Each parent node has at most two children nodes (that's why it's called a 'binary' tree) regardless of their order.
 * 
 * 
 * Binary search trees are a special type of binary tree where the left child node is always less than the parent node, and the right child node is always greater than the parent node.
 */

class BinarySearchTree {
  private:
    static Node *root;

  public:
    BinarySearchTree() {
      root = nullptr;
    }

    ~BinarySearchTree() {
      delete root;
    }

    void insert(int value) {
      Node *newNode = new Node(value);

      if (root == nullptr) {
        root = newNode;
      } else {
        Node *current = root;
      }
    }

    Node* insertRecursive(Node *current, Node *newNode) {
      if (current == nullptr) {
        return newNode;
      }

      if (newNode->data < current->data) {
        if (current->left == nullptr) {
          current->left = newNode;
          newNode->parent = current;
        } else {
          insertRecursive(current->left, newNode);
        }
      } else if (newNode->data > current->data) {
        if (current->right == nullptr) {
          current->right = newNode;
          newNode->parent = current;
        } else {
          insertRecursive(current->right, newNode);
        }
      }

      return current;
    }
    
    int countNodes() {}

    // Different variants of Deapth First Search
    void inOrder(Node *current = root) {
      if (current == nullptr)
        return;
      
      inOrder(current->left);
      cout << current->data << endl;
      inOrder(current->right);
    }

    void preOrder(Node *current = root) {
      if (current == nullptr) {
        return;
      }

      cout << current->data << endl;
    }
    
    void postOrder(Node *current = root) {
      if (current == nullptr)
        return;

      postOrder(current->left);
      postOrder(current->right);
      cout << current->data << endl;
    }

    // Different variant of Breadth First Search
    void levelOrder(Node *current = root) {
      if (current == nullptr)
        return;

      // We use a queue to implement a BFS traversal
      queue<Node*> q;

      q.push(current);

      while (!q.empty()) {
        Node *current = q.front();
        cout << current->data << endl;
        q.pop();

        if (current->left != nullptr)
          q.push(current->left);
        if (current->right != nullptr)
          q.push(current->right);
      }
    }

    Node* search() {}
    Node* searchRecursive() {}

    Node* findMin() {}
    Node* findMax() {}

    void deleteNode(Node* node) {}

};

int main() {
  cout << "Binary search trees" << endl;
  return 0;
}

