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

class Stack {
  // The stack property here lives on the heap

  private:
    int top;
    int *stack;

    bool isEmpty() {
      return top == -1;
    }

  public:
    Stack(int size) {
      this->top = -1;
      this->stack = new int[size];
    }

    ~Stack() {
      delete[] this->stack;
    }
};

int main()
{
  cout << "Stack" << endl;
  return 0;
}