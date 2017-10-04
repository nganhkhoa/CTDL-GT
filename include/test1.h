#ifndef TEST1_H
#define TEST1_H

#include <iostream>

namespace test1
{
namespace prepare
{
      struct LinkedList
      {
            struct node
            {
                  int   data;
                  node* next;

                  node(int d = 0, node* n = NULL) : data(d), next(n) {}
            };

            node* head;
            int   count;

            LinkedList() {
                  head  = NULL;
                  count = 0;
            }

            int size() const {
                  return count;
            }
            bool empty() const {
                  return size() == 0;
            }
            bool full() const {
                  node* n = new node();
                  if (n) {
                        delete n;
                        return false;
                  }
                  return true;
            }

            void clear() const {
                  while (!empty()) {
                  }
            }
            void insert() {}
            void remove() {}
      };

      struct stack
      {
            struct node
            {
                  int   data;
                  node* next;

                  node(int d = 0, node* n = NULL) : data(d), next(n) {}
            };

            node* top;
            int   count;

            stack() {
                  top   = NULL;
                  count = 0;
            }

            inline int size() const {
                  return count;
            }
            inline bool empty() const {
                  return size() == 0;
            }

            void push(int d) {
                  if (empty())
                        top = new node(d);
                  else
                        top = new node(d, top);
                  ++count;
            }
            void pop() {
                  if (empty())
                        return;
                  node* removeThis = top;
                  top              = top->next;
                  delete removeThis;
                  removeThis = NULL;
                  --count;
            }
            int& top() {
                  return top->data;
            }
      };

      struct queue
      {
            struct node
            {
                  int   data;
                  node* next;

                  node(int d = 0, node* n = NULL) : data(d), next(n) {}
            };

            node* front;
            node* rear;
            int   count;

            queue() {
                  front = NULL;
                  rear  = NULL;
                  count = 0;
            }

            inline int size() const {
                  return count;
            }
            inline bool empty() const {
                  return size() == 0;
            }

            int& front() {
                  return front->data;
            }
            int& rear() {
                  return rear->data;
            }

            void enqueue(int d) {
                  if (empty())
                        front = rear = new node(d);
                  else
                        rear = rear->next = new node(d);
                  ++count;
            }
            void dequeue() {
                  if (empty())
                        return;
                  node* removeThis = front;
                  front            = front->next;
                  delete removeThis;
                  removeThis = NULL;
                  --count;
            }
      };
}    // namespace prepare
namespace test
{}    // namespace test
}    // namespace test1

#endif