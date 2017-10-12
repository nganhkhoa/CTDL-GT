#ifndef TEST1_H
#define TEST1_H

#include <iostream>

namespace test1
{
namespace prepare
{}    // namespace prepare
namespace L02
{
      class Stack {
          private:
            struct node
            {
                  int   data;
                  node* next;
                  node(int d = 0, node* n = NULL) : data(d), next(n) {}
            };
            typedef int size_t;
            size_t      capacity;
            size_t      _size;
            node*       _top;

          public:
            Stack(size_t cap = 3) : capacity(cap) {
                  _size = 0;
                  _top  = NULL;
            }

            inline size_t size() const {
                  return _size;
            }

            inline bool empty() {
                  return size() == 0;
            }

            inline bool full() {
                  return size() == capacity;
            }

            bool push(int data) {
                  if (full())
                        return false;
                  _top = new node(data, _top);
                  ++_size;
                  return true;
            }
            bool pop() {
                  if (empty())
                        return false;
                  node* removeThis = _top;
                  _top             = _top->next;
                  delete removeThis;
                  removeThis = NULL;
                  --_size;
                  return true;
            }
            int& top() {
                  if (empty()) {
                        std::cout << "Nothing to return\n";
                        return *(new int());
                  }
                  return _top->data;
            }

            friend std::ostream& operator<<(std::ostream& o, const Stack& s) {
                  auto temp = s._top;

                  o << "TOP: ";
                  while (temp) {
                        o << temp->data;
                        o << " <-- ";
                        temp = temp->next;
                  }
                  o << "END STACK";
                  return o;
            }
      };

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

            bool insertAt(size_t place = 1, int data = 0) {
                  if (place > size() + 1)
                        return false;
                  if (place < 1)
                        return false;

                  node* preNode = _head;
                  while (--place)
                        preNode = preNode->next;
                  preNode->next = new node(data, preNode->next);
                  ++_size;
                  preNode = NULL;
                  return true;
            }

            bool removeAt(size_t place = 0) {
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

            friend std::ostream&
               operator<<(std::ostream& o, const LinkedList& l) {
                  auto temp = l._head->next;

                  while (temp) {
                        o << temp->data;
                        o << " --> ";
                        temp = temp->next;
                  }
                  o << "END";
                  return o;
            }

            void reverse_using_stack() {
                  Stack* stack = new Stack(size());

                  while (!empty()) {
                        stack->push(_head->next->data);
                        removeAt(1);
                  }

                  while (!stack->empty()) {
                        insertAt(size() + 1, stack->top());
                        stack->pop();
                  }
            }

            void reverse_using_queue() {
                  Queue* queue = new Queue();

                  while (!empty()) {
                        queue->enqueue(_head->next->data);
                        removeAt(1);
                  }

                  while (!queue->empty()) {
                        insertAt(1, queue->front());
                        queue->dequeue();
                  }
            }
      };

      void Test();
}    // namespace L02

namespace L01
{
      struct node
      {
            int   data;
            node* next;

            node(int d = 0, node* n = NULL) : data(d), next(n) {}
      };

      
      void Test();
}    // namespace L01
}    // namespace test1

#endif