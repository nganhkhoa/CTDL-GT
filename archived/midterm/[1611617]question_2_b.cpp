#include "[1611617]LinkedList.h"

#include <iostream>


bool LinkedList::removeAt(size_t place = 0) {
      if (place > size())
            return false;
      if (place < 1)
            return false;

      node* preNode = _head;
      while (--place)
            preNode = preNode->next;

      node* removeThis = preNode->next;
      preNode->next    = removeThis->next;

      delete removeThis;
      removeThis = NULL;
      preNode    = NULL;
      --_size;
      return true;
}