#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

#include <SinglyLinkedList.h>

#include <iostream>

namespace data
{
template <class data_type>
class Stack_LinkedList : protected SinglyLinkedList<data_type> {

    public:
      Stack_LinkedList<data_type>() : SinglyLinkedList<data_type>() {}

    public:
      void pop() {
            SinglyLinkedList<data_type>::removeHead();
      }

      void push(const data_type& d) {
            SinglyLinkedList<data_type>::insertHead(d);
      }

      friend std::ostream&
         operator<<(std::ostream& o, const Stack_LinkedList<data_type>& s) {
            for (auto& x : s)
                  o << x << " --> ";
            o << "NULL";
            return o;
      }

      data_type& top() {
            return SinglyLinkedList<data_type>::front();
      }
};
}

#endif