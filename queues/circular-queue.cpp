#include <iostream>

using namespace std;

class Queue {
  private:
    int front;
    int rear;
    int capacity;
    int* queue;
    int size;

  public: 
    Queue(int capacity) {
      this->front = -1;
      this->rear = -1;
      this->size = 0;
      this->capacity = capacity;
      this->queue = new int[capacity];
    }

    ~Queue() {
      delete[] queue;
    }

    void enqueue(int value) {
      if (isFull()) {
        cout << "Queue is overflowing" << endl;
        return;
      }

      if (front == -1)
        front = 0;

      queue[(rear + 1) % capacity] = value;
      size++;
    }

    void dequeue() {
      if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
      }

      front = (front + 1) % capacity;
      size--;
    }

    int peek() {
      if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
      }

      return queue[front];
    }

    int getRear() {
      if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
      }

      return queue[rear];
    }  

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    bool isFull() {
      return size == capacity;
    }
};

int main() {
  cout << "Queue" << endl;
  return 0;
}