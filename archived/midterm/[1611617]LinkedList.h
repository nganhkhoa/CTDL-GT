#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList {
    private:
      struct node
      {
            int   data;
            node* next;

            node(int d = 0, node* n = NULL) : data(d), next(n) {}
      };

      typedef int size_t;
      node*       _head;
      size_t      _size;

    public:
      LinkedList() {
            _head = new node();
            _size = 0;
      }

      inline size_t size() const {
            return _size;
      }

      inline bool empty() const {
            return size() == 0;
      }

      bool insertAt(size_t, int);

      bool removeAt(size_t);

      friend std::ostream& operator<<(std::ostream& o, const LinkedList& l) {
            auto temp = l._head->next;

            while (temp) {
                  o << temp->data;
                  o << " --> ";
                  temp = temp->next;
            }
            o << "END";
            return o;
      }

      void reverse_using_stack();

      void reverse_using_queue();
};

#endif