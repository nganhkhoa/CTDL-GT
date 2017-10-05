#ifndef TEST1_H
#define TEST1_H

#include <iostream>

namespace test1
{
namespace prepare
{}    // namespace prepare
namespace test
{
      struct LinkedList
      {
            struct node
            {
                  int   data;
                  node* next;

                  node(int d = 0, node* n = NULL) : data(d), next(n) {}
            };

            typedef int size_t;
            node*       _head;
            size_t      _size;

            LinkedList() {
                  _head = new node();
                  _size = 0;
            }

            size_t size() const {
                  return _size;
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
      };
      void Test();
}    // namespace test
}    // namespace test1

#endif