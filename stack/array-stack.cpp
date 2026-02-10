#include <iostream>
using namespace std;

/**
 *
 * A stack is a linear data structure that stores items in a Last-In-First-Out (LIFO) manner.
 * This means that the last item added to the stack is the first one to be removed.
 *
 * It is used in stynatx parsing and expression evaluation.
 * It is used to store function calls in a function call stack.
 * It's also thanks to stacks that we can implement recursive functions.
 *
 */

class Stack
{
  // The stack property here lives on the heap
private:
  int top;
  int *stack;
  int size;

public:
  Stack(int size)
  {
    this->size = size;
    this->top = -1;
    this->stack = new int[size];
  }

  ~Stack()
  {
    delete[] this->stack;
  }

  bool isEmpty()
  {
    return this->top == -1;
  }

  bool isFull()
  {
    return this->top == this->size - 1;
  }

  void push(int value)
  {
    if (this->isFull())
    {
      cout << "Stack is full" << endl;
      return;
    }

    this->top++;
    this->stack[this->top] = value;
  }

  int pop()
  {
    if (this->isEmpty())
    {
      cout << "Stack is empty" << endl;
      return -1;
    }

    return this->stack[this->top--];
  }

  int peek()
  {
    if (this->isEmpty())
    {
      return -1;
    }

    return this->stack[this->top];
  }
};

int main()
{
  cout << "Stack" << endl;
  return 0;
}