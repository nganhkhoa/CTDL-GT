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
      ~Queue_LinkedList<data_type>() {}

    public:
      void enqueue(const data_type& d) {
            SinglyLinkedList<data_type>::insertEnd(d);
      }
      void dequeue() {
            SinglyLinkedList<data_type>::removeHead();
      }

      void clear() {
            while (size())
                  dequeue();
      }

      size_t size() const {
            return SinglyLinkedList<data_type>::size();
      }

      bool isEmpty() const {
            return size() == 0;
      }

      friend std::ostream&
         operator<<(std::ostream& o, const Queue_LinkedList<data_type>& q) {
            o << "FRONT <-- ";
            for (auto& x : q)
                  o << x << " <-- ";
            o << "REAR";
            return o;
      }

      data_type& front() {
            return SinglyLinkedList<data_type>::front();
      }

      data_type& rear() {
            return SinglyLinkedList<data_type>::back();
      }
};
}    // namespace data

#endif