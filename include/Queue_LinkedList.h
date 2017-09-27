#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <SinglyLinkedList.h>

#include <iostream>

namespace data
{
template <class data_type>
class Queue_LinkedList : protected SinglyLinkedList<data_type> {
    public:
      Queue_LinkedList<data_type>() : SinglyLinkedList<data_type>() {}

      void enqueue(const data_type& d) {
            SinglyLinkedList<data_type>::insertEnd(d);
      }
      void dequeue() {
            SinglyLinkedList<data_type>::removeHead();
      }

      friend std::ostream&
         operator<<(std::ostream& o, const Queue_LinkedList<data_type>& q) {
            for (auto& x : q)
                  o << x << " --> ";
            o << "NULL";
            return o;
      }
};
}

#endif