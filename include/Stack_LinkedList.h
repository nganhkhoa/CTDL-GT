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
      ~Stack_LinkedList<data_type>() {}

    public:
      void pop() {
            SinglyLinkedList<data_type>::removeHead();
      }

      void push(const data_type& d) {
            SinglyLinkedList<data_type>::insertHead(d);
      }

      void clear() {
            while (size())
                  pop();
      }

      size_t size() const {
            return SinglyLinkedList<data_type>::size();
      }

      bool isEmpty() const {
            return size() == 0;
      }

      friend std::ostream&
         operator<<(std::ostream& o, const Stack_LinkedList<data_type>& s) {
            o << "TOP <-- ";
            for (auto& x : s)
                  o << x << " <-- ";
            o << "END STACK";
            return o;
      }

      data_type& top() {
            return SinglyLinkedList<data_type>::front();
      }
};
}    // namespace data

#endif