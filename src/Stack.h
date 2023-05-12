#pragma once

template <typename T>
class Stack
{
  struct Node
  {
    T data;
    Node *next;

    Node(const T &value) : data{value}, next{nullptr} {}
  };
};