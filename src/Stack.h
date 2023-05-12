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
    size += 1;
  }

  void pop()
  {
    if (!isEmpty())
    {
      Node *temp = topNode;
      topNode = topNode->next;
      delete temp;
      size -= 1;
    }
    else
    {
      throw runtime_error("Stack underflow: Cannot pop from an empty stack.")
    }
  }

  T &top()
  {
    if (!isEmpty())
    {
      return topNode->data;
    }
    else
    {
      throw runtime_error("Stack underflow: Stack is empty.")
    }
  }

  const T &top() const
  {
    if (!isEmpty())
    {
      return topNode->data;
    }
    else
    {
      throw runtime_error("Stack underflow: Stack is empty.")
    }
  }

  size_t size() const { return size; }
};