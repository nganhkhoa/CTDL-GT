#include "[1611617]LinkedList.h"

#include <iostream>


bool LinkedList::insertAt(size_t place = 0, int data = 0) {
      if (place > size() + 1)
            return false;
      if (place < 1)
            return false;

      // find prenode
      node* preNode = _head;
      while (--place)
            preNode = preNode->next;

      preNode->next = new node(data, preNode->next);

      // post clean ups
      preNode = NULL;
      ++_size;
      return true;
}