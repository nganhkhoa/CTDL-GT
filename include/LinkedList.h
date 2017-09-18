#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace book
{

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
            _size       = 0;
            _head       = new node();
            _tail       = new node();
            _head->next = _tail;
            _tail->prev = _head;
      }

    public:
      class const_iterator {
          protected:
            const LinkedList<data_type>* list;
            node*                        current;
            data_type&                   retrieve() const {
                  return current->data;
            }

            const_iterator(const LinkedList<data_type>& l, node* n)
                : list(&l), current(n) {}

            void valid() const {
                  if (
                     (list == NULL) || (current == NULL) ||
                     (current == list->_head))
                        throw "IteratorOutOfBoundException";
            }

            friend class LinkedList<data_type>;

          public:
            const_iterator() : current(nullptr) {}

            const data_type& operator*() const {
                  return retrieve();
            }

            // ++node
            const_iterator& operator++() {
                  current = current->next;
                  return *this;
            }
            // node++
            const_iterator operator++(int) {
                  const_iterator old = *this;
                  ++(*this);
                  return old;
            }

            bool operator==(const const_iterator& it) const {
                  return current == it.current;
            }
            bool operator!=(const const_iterator& it) const {
                  return !((*this) == it);
            }
      };

      class iterator : public const_iterator {
          protected:
            iterator(const LinkedList<data_type>& l, node* n)
                : const_iterator(l, n) {}
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
                  this->current = this->current->next;
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
            iterator it(*this, _head);
            return ++it;
      }
      const_iterator begin() const {
            const_iterator it(*this, _head);
            return ++it;
      }

      iterator end() {
            return {*this, _tail};
      }
      const_iterator end() const {
            return {*this, _tail};
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

      friend std::ostream&
         operator<<(std::ostream& o, const LinkedList<data_type>& l) {
            for (auto it = l.begin(); it != l.end(); it++)
                  o << *it << " --> ";
            o << " NULL";
            return o;
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
      LinkedList(data_type (&arr)[size]) {
            init();
            for (size_t i = 0; i < size; i++)
                  push_back(arr[i]);
      }
      LinkedList(data_type* arr, size_t size) {
            init();
            for (size_t i = 0; i < size; i++)
                  push_back(arr[i]);
      }

      LinkedList& operator=(const LinkedList& l) {
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
      iterator insert(iterator it, const data_type& d) {
            it.valid();
            if (it.list != this)
                  throw "IteratorMismatchException";

            node* n = it.current;
            _size++;
            return {*this, n->prev = n->prev->next = new node(d, n->prev, n)};
      }

      iterator erase(iterator it) {
            node*    n = it.current;
            iterator returnValue(*this, n->next);
            n->next->prev = n->prev;
            n->prev->next = n->next;
            delete n;
            _size--;
            return returnValue;
      }
      iterator erase(iterator from, iterator to) {
            for (auto it = from; it != to;)
                  it = erase(it);
            return to;
      }

      data_type& operator[](size_t index) {
            if (index < 0 || index >= _size)
                  throw "Index out of range";
            auto it = begin();
            while (index-- > 0)
                  it++;
            return *it;
      }
};
}    // namespace book
#endif