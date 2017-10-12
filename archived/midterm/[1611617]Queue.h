#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
      struct node
      {
            int   data;
            node* next;
            node(int d = 0, node* n = NULL) : data(d), next(n) {}
      };

      typedef int size_t;
      size_t      _size;
      node*       _front;
      node*       _rear;

    public:
      Queue() {
            _size  = 0;
            _front = NULL;
            _rear  = NULL;
      }

      inline size() const {
            return _size;
      }

      inline empty() const {
            return size() == 0;
      }

      int& front() {
            if (empty()) {
                  std::cout << "Nothing to return\n";
                  return *(new int());
            }
            return _front->data;
      }

      bool enqueue(int d) {
            if (empty()) {
                  _front = _rear = new node(d);
            }
            else {
                  _rear = _rear->next = new node(d);
            }
            ++_size;
            return true;
      }

      bool dequeue() {
            if (empty())
                  return false;
            node* removeThis = _front;
            _front           = _front->next;
            delete removeThis;
            removeThis = NULL;
            --_size;
            if (empty()) {
                  _front = _rear = NULL;
            }
            return true;
      }
};

#endif