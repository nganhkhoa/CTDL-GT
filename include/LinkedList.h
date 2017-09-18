#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class data_type>
class LinkedList {
    public:
      typedef int size_t;

    protected:
      struct node
      {
            data_type data;
            node*     next;
            node*     prev;

            node(
               const data_type& d = data_type(),
               node*            p = nullptr,
               node*            n = nullptr)
                : data(d), next(n), prev(p) {}
      };

      size_t _size;
      node*  _head;
      node*  _tail;

      void init() {
            _size = 0;
            _head = new node();
      }

    public:
      class const_iterator {
          protected:
            node*      current;
            data_type& retrieve() const {
                  return current->data;
            }
            const LinkedList<data_type>* list;

            const_iterator(const LinkedList<data_type>& l, node* n)
                : list(&l), current(n) {}

            void valid() const {
                  if (
                     (list == NULL) || (current == NULL) ||
                     (current == list->_head))
                        throw IteratorOutOfBoundException();
            }

            friend class LinkedList<data_type>;

          public:
            const_iterator() : current(nullptr) {}

            const data_type& operator*() const {
                  return retrieve();
            }

            // ++node
            const_iterator& operator++() const {
                  current = current->next;
                  return *this;
            }
            // node++
            const_iterator operator++(int) const {
                  const_iterator old = *this;
                  ++(*this);
                  return old;
            }

            bool operator==(const const_iterator& it) {
                  return current == it.current;
            }
            bool operator!=(const const_iterator& it) {
                  return !((*this) == it);
            }
      };

      class iterator : public const_iterator {
          protected:
            iterator(node* n) : const_iterator(n) {}
            friend class LinkedList<data_type>;

          public:
            iterator() {}

            data_type& operator*() {
                  return const_iterator::retrieve();
            }
            const data_type& operator*() const {
                  return const_iterator::retrieve();
            }

            // ++node
            iterator operator++() {
                  current = current->next;
                  return (*this);
            }
            // node++
            iterator operator++(int) {
                  iterator old = *this;
                  ++(*this);
                  return old;
            }
      };


    public:
      iterator begin() {
            return _head->next;
      }
      iterator end() {
            return _tail;
      }

      const_iterator begin() {
            return _head->next;
      }
      const_iterator end() {
            return _tail;
      }

      size_t size() const {
            return _size;
      }

      bool isEmpty() const {
            return _size == 0;
      }

      void clear() {
            while (!isEmpty())
                  pop_front();
      }

    public:
      data_type& front() {
            return *begin();
      }
      const data_type& front() const {
            return *begin();
      }
      data_type& back() {
            return *--end();
      }
      const data_type& back() const {
            return *--end();
      }

      void push_front(const data_type& d) {
            insert(begin(), d);
      }
      void push_back(const data_type& d) {
            insert(end(), d);
      }

      void pop_front() {
            erase(begin());
      }
      void pop_back() {
            erase(--end());
      }

    public:
      LinkedList() {
            init();
      }
      LinkedList(const LinkedList& l) {
            init();
            for (auto& x : l)
                  push_back(x);
      }

      template <size_t size>
      LinkedList(data_type (&arr)[size]) {}
      LinkedList(data_type* arr, size_t size) {}

      LinkedList& operator=(cosnt LinkedList& l) {
            clear();
            for (auto& x : l)
                  push_back(x);
            return (*this);
      }

      ~LinkedList() {
            clear();
            delete _head;
            delete _tail;
      }

    public:
      iterator insert(iterator it, const& data_type& d) {
            node* n = it.current;
            _size++;
            return {n->prev = n->prev->next = new node(d, n->prev, n)};
      }

      iterator erase(iterator it) {
            node*    n = it.current;
            iterator returnValue(n->next);
            n->next->prev = n->prev;
            n->prev->next = n->next;
            delete n;
            _size--;
            return returnValue;
      }
      iterator erase(iterator from, iterator to) {
            for (auto it = from, it != to;)
                  it = erase(it);
            return to;
      }
};

#endif