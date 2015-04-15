#ifndef STACK_H
#define STACK_H

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class Stack
{
public:
  Stack();
  void push(const T&);
  void pop();
  T top() const;
  unsigned int size() const;
  bool empty() const;
private:
  vector<T> dati;
};

template <class T>
Stack<T>::Stack()
{}

template <class T>
void Stack<T>::push(const T &element)
{
  dati.push_back(element);
}

template <class T>
void Stack<T>::pop()
{
  assert(!dati.empty());
  dati.pop_back();
}

template <class T>
T Stack<T>::top() const
{
  assert(!dati.empty());
  return dati.back();
}

template <class T>
unsigned int Stack<T>::size() const
{
  return dati.size();
}

template <class T>
bool Stack<T>::empty() const
{
 return dati.empty();
}

#endif

