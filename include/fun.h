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
      intList->clear();

      intList->insertEnd(0);
      intList->insertEnd(1);
      intList->insertEnd(2);
      intList->insertEnd(3);
      intList->insertEnd(4);
      intList->insertEnd(5);

      std::cout << "Using for loop 1:\n";
      for (auto& x : *intList)
            std::cout << x++ << " ";
      std::cout << "\n";

      std::cout << "Using for loop 2:\n";
      for (auto it = intList->begin(); it != intList->end(); ++it)
            std::cout << *it << " ";
      std::cout << "\n";
}
}
#endif