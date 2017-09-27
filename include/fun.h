#ifndef FUN_H
#define FUN_H

#include <SinglyLinkedList.h>
#include <Stack_LinkedList.h>
#include <Queue_LinkedList.h>

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


inline void Stack_LinkedListTest() {
      data::Stack_LinkedList<int>* stack = new data::Stack_LinkedList<int>();
      stack->push(0);
      stack->push(1);
      stack->push(2);

      std::cout << *stack << std::endl;

      stack->pop();
      std::cout << *stack << std::endl;
}

inline void Queue_LinkedListTest() {
      data::Queue_LinkedList<int>* queue = new data::Queue_LinkedList<int>();
      queue->enqueue(0);
      queue->enqueue(1);
      queue->enqueue(2);

      std::cout << *queue << std::endl;

      queue->dequeue();
      std::cout << *queue << std::endl;
}
}
#endif