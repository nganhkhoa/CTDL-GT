#ifndef FUN_H
#define FUN_H

#include <SinglyLinkedList.h>

#include <iostream>

namespace fun
{

inline void SinglyLinkedListTest() {
      data::SinglyLinkedList<int>* intList = new data::SinglyLinkedList<int>();
      std::cout << *intList << std::endl;
      intList->insertHead(0);
      intList->insertEnd(1);
      std::cout << *intList << std::endl;
      intList->removeHead();
      std::cout << *intList << std::endl;
      intList->removeHead();
      std::cout << *intList << std::endl;

      intList->insertHead(0);
      intList->insertEnd(1);
      intList->removeEnd();
      std::cout << *intList << std::endl;
}
}
#endif