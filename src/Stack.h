#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
  struct Node
  {
    T data;
    Node *next;

    Node(const T &value) : data{value}, next{nullptr} {}
  };

  Node *topNode;
  size_t size;

public:
  Stack() : topNode(nullptr), size{0} {}

  bool isEmpty() const
  {
    return (topNode == nullptr);
  }

  void push(const T &element)
  {
    Node *newNode = new Node(element);
    newNode->next = topNode;
    topNode = newNode;
  }

  void pop()
  {
    if (!isEmpty())
    {
      Node *temp = topNode;
      topNode = topNode->next;
      delete temp;
    }
    else
    {
      throw runtime_error("Stack underflow: Cannot pop from an empty stack.")
    }
  }
};