#include "towers.h"
#include <iostream>

Towers::Towers(int numDisks) : numDisk(numDisks) {
  peg1 = new MyStack<int>(numDisk);
  peg2 = new MyStack<int>(numDisk);
  peg3 = new MyStack<int>(numDisk);
}

Towers::~Towers() {
  delete peg1;
  delete peg2;
  delete peg3;
}

Towers::Towers(const Towers &other) {}

Towers &Towers::operator=(const Towers &other) { return *this; }

void Towers::start() {
  setDisks();
  move(numDisk, peg1, peg2, peg3);
}

void Towers::setDisks() {
  for (int i = numDisk; i >= 1; --i) {
    peg1->push(i);
  }
  plotPegs();
}

void Towers::plotPegs() {
  if (peg1 == nullptr || peg2 == nullptr || peg3 == nullptr)
    return;

  int n1 = peg1->size();
  int n2 = peg2->size();
  int n3 = peg3->size();
  int numDisk = n1 + n2 + n3;

  MyStack<int> tmp1(*peg1);
  MyStack<int> tmp2(*peg2);
  MyStack<int> tmp3(*peg3);

  // Plot
  for (int i = 0; i < numDisk; ++i) {
    // Peg 1
    if (numDisk - n1 - i > 0) {
      for (int j = 0; j < numDisk; ++j)
        std::cout << " ";
    } else {
      int m1 = tmp1.top();
      tmp1.pop();
      for (int j = 0; j < m1; ++j)
        std::cout << "*";
      for (int j = m1; j < numDisk; ++j)
        std::cout << " ";
    }
    std::cout << " | ";

    // Peg 2
    if (numDisk - n2 - i > 0) {
      for (int j = 0; j < numDisk; ++j)
        std::cout << " ";
    } else {
      int m2 = tmp2.top();
      tmp2.pop();
      for (int j = 0; j < m2; ++j)
        std::cout << "*";
      for (int j = m2; j < numDisk; ++j)
        std::cout << " ";
    }
    std::cout << " | ";

    // Peg 3
    if (numDisk - n3 - i > 0) {
      for (int j = 0; j < numDisk; ++j)
        std::cout << " ";
    } else {
      int m3 = tmp3.top();
      tmp3.pop();
      for (int j = 0; j < m3; ++j)
        std::cout << "*";
      for (int j = m3; j < numDisk; ++j)
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "_________________________________________" << std::endl;
}

void Towers::move(int n, MyStack<int> *source, MyStack<int> *temp,
                  MyStack<int> *dest) {
  if (n == 1) {
    moveOne(source, dest);
    plotPegs();
  } else {
    move(n - 1, source, dest, temp);
    moveOne(source, dest);
    plotPegs();
    move(n - 1, temp, source, dest);
  }
}

void Towers::moveOne(MyStack<int> *source, MyStack<int> *dest) {
  int disk = source->pop();
  dest->push(disk);
}