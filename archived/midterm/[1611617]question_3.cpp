#include "[1611617]Stack.h"

#include <iostream>

inline bool Stack::empty() {
      return size() == 0;
}

inline bool Stack::full() {
      return size() == capacity;
}

bool Stack::push(int data) {
      if (full())
            return false;
      _top = new node(data, _top);
      ++_size;
      return true;
}

bool Stack::pop() {
      if (empty())
            return false;
      node* removeThis = _top;
      _top             = _top->next;
      delete removeThis;
      removeThis = NULL;
      --_size;
      return true;
}