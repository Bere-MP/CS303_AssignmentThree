#pragma once
#include <iostream>

using namespace std;

// define class Queue

class Queue {
  private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front, rear;
  
  public:
    Queue();
    void enqueue(int element);
    int dequeue();
    int peek();
    bool isEmpty();
    int size();
};
