#include "Queue.h"

// Constructor
Queue::Queue() {
  front = -1;
  rear = -1;
}

// Function to add an element to the queue
void Queue::enqueue(int element) {
  if (rear == MAX_SIZE - 1) {
    cout << "Queue Error" << endl;
    return;
  }

  if (isEmpty()) {
    front = 0;
  }

  arr[++rear] = element;
  cout << "Enqueued: " << element << endl;
}

// Function to remove an element from the queue
int Queue::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }

  int element = arr[front++];
  cout << "Dequeued: " << element << endl;

  if (front > rear)
    front = rear = -1;

  return element;
}

// Function to return the front element of the queue
int Queue::peek() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }

  else
    return arr[front];
}

// Function to check if the queue is empty
bool Queue::isEmpty() {
  if (front == -1 && rear == -1)
    return true;
  else
    return false;
}

// Function to display the size of the queue
int Queue::size() {
  if (isEmpty()) {
    return 0;
  }
  return (rear - front + 1);
}

/*
Reference:
-https://codereview.stackexchange.com/questions/238448/implementing-a-queue-in-c
-https://www.techiedelight.com/queue-implementation-cpp/
*/
