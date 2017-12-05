#ifndef BTREE_H
#define BTREE_H

#include <SinglyLinkedList.h>
#include <iostream>
#include <cmath>

namespace data
{

template <class data_type, int max_degree>
class BTree {

      struct node
      {
            // 24 bytes
            // list have method to insert without sorting
            SinglyLinkedList<data_type>* keys;
            node**                       children;
            size_t                       capacity;

            node(int degree) {
                  keys     = new SinglyLinkedList<data_type>();
                  children = nullptr;
                  capacity = degree - 1;
            }

            size_t size() const {
                  return keys->size();
            }

            bool isEmpty() const {
                  return size() == 0;
            }

            bool isFull() const {
                  return size() == capacity;
            }

            bool overflow() const {
                  return size() > capacity;
            }

            bool underflow() const {
                  return size() < std::ceil((capacity + 1) / 2) - 1;
            }

            void insert(data_type& d) {
                  keys->insertSort(d);
            }

            void remove() {
                  keys->removeHead();
            }

            node* rebalance() {
                  return nullptr;
            }
      };

      // 32 bytes
      // small bits
      node*  root;
      size_t _size;       // current elements
      size_t capacity;    // max elements before resize
      size_t degree;      // the degree


      void extend(node* n) {
            if (n->children == nullptr) {

                  n->children = new node*[degree];
                  for (size_t i = 0; i < degree; ++i) {
                        n->children[i] = new node(degree);
                        capacity += degree - 1;
                  }

                  size_t    middle = n->size() / 2;
                  data_type head;
                  for (size_t i = 0;; ++i) {
                        if (i == n->capacity)
                              break;

                        data_type& d = n->keys->front();

                        if (i < middle) {
                              n->children[0]->insert(d);
                        }
                        else if (i > middle) {
                              n->children[1]->insert(d);
                        }
                        else {
                              head = d;
                        }

                        n->remove();
                  }
                  n->insert(head);
            }
            else
                  for (size_t i = 0; i < degree; ++i)
                        extend(n->children[i]);
      }

      void insert(node*& n, data_type& d) {
            // n will never be null
            // because we have extend space for it

            // if leaf
            if (n->children == nullptr) {
                  n->insert(d);
                  return;
            }

            // not leaf, go in
            size_t idx = 0;
            for (data_type& data : *n->keys) {
                  if (data > d)
                        break;
                  else
                        idx++;
            }

            insert(n->children[idx], d);

            n = n->rebalance();
      }

    public:
      BTree() {
            _size    = 0;
            capacity = max_degree - 1;
            degree   = max_degree;
            root     = new node(degree);
      }

      size_t size() const {
            return _size;
      }

      bool isEmpty() const {
            return size() == 0;
      }

      bool isFull() const {
            return size() == capacity;
      }

      void insert(data_type d) {
            insert(root, d);
            _size++;
      }
};
}    // namespace data

#endif