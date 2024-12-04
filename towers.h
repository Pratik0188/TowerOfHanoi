#ifndef TOWERS_H
#define TOWERS_H

#include "mystack.h"

class Towers {
private:
  MyStack<int> *peg1;
  MyStack<int> *peg2;
  MyStack<int> *peg3;
  int numDisk;

public:
  Towers(int);
  ~Towers();
  Towers(const Towers &);
  Towers &operator=(const Towers &);
  void start();

private:
  void setDisks();
  void plotPegs();
  void move(int, MyStack<int> *, MyStack<int> *, MyStack<int> *);
  void moveOne(MyStack<int> *, MyStack<int> *);
};

#endif
