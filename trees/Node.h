#ifndef NODE_H
#define NODE_H

struct Node {
  int data;
  Node *left;
  Node *right;
  Node *parent;

  Node(int value): data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

#endif