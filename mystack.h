#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

template <class T> class MyStack {
private:
  T *stackArray;
  int stackSize;
  int numElem;

public:
  MyStack(int);
  MyStack(const MyStack &);
  MyStack &operator=(const MyStack &);
  ~MyStack();
  void push(T);
  T pop();
  T top();
  bool isFull() const;
  bool isEmpty() const;
  int size() const;
};

template <class T> MyStack<T>::MyStack(int size) : stackSize(size), numElem(0) {
  stackArray = new T[size];
}

template <class T>
MyStack<T>::MyStack(const MyStack &other)
    : stackSize(other.stackSize), numElem(other.numElem) {
  stackArray = new T[stackSize];
  for (int i = 0; i < numElem; ++i) {
    stackArray[i] = other.stackArray[i];
  }
}

template <class T> MyStack<T> &MyStack<T>::operator=(const MyStack &other) {
  if (this != &other) {
    delete[] stackArray;
    stackSize = other.stackSize;
    numElem = other.numElem;
    stackArray = new T[stackSize];
    for (int i = 0; i < numElem; ++i) {
      stackArray[i] = other.stackArray[i];
    }
  }
  return *this;
}

template <class T> MyStack<T>::~MyStack() { delete[] stackArray; }

template <class T> void MyStack<T>::push(T value) {
  if (!isFull()) {
    stackArray[numElem++] = value;
  } else {
    std::cerr << "Stack is full. Cannot push." << std::endl;
  }
}

template <class T> T MyStack<T>::pop() {
  if (!isEmpty()) {
    return stackArray[--numElem];
  } else {
    std::cerr << "Stack is empty. Cannot pop." << std::endl;
    return T();
  }
}

template <class T> T MyStack<T>::top() {
  if (!isEmpty()) {
    return stackArray[numElem - 1];
  } else {
    std::cerr << "Stack is empty. No top element." << std::endl;
    return T();
  }
}

template <class T> bool MyStack<T>::isFull() const {
  return numElem == stackSize;
}

template <class T> bool MyStack<T>::isEmpty() const { return numElem == 0; }

template <class T> int MyStack<T>::size() const { return numElem; }

#endif
