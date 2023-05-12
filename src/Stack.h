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

public:
  Stack() : topNode(nullptr) {}
};