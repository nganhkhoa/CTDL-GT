#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace data
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
      /*!
       * Iterator class const and non-const
       */
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
            // --node
            const_iterator& operator--() {
                  current = current->prev;
                  return *this;
            }
            // node--
            const_iterator& operator--(int) {
                  const_iterator old = *this;
                  --(*this);
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
            // --node
            iterator operator--() {
                  this->current = this->current->prev;
                  return (*this);
            }
            // node--
            iterator operator--(int) {
                  iterator old = *this;
                  --(*this);
                  return old;
            }
      };


    public:
      /*!
       * Iterator for using for-ranged loop
       */
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

    public:
      /*!
       * Quick get
       */
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

      /*!
       * Insert and remove
       */
      void insertHead(const data_type& d) {
            insert(begin(), d);
      }
      void insertEnd(const data_type& d) {
            insert(end(), d);
      }
      void insertAt(size_t place, const data_type& d) {
            if (place <= 0)
                  insertHead(d);
            else if (place >= size())
                  insertEnd(d);
            else {
                  auto it = begin();
                  while (place--)
                        it++;
                  insert(it, d);
            }
      }

      void removeHead() {
            erase(begin());
      }
      void removeEnd() {
            erase(--end());
      }
      void removeAt(size_t place, const data_type& d) {
            if (place <= 0)
                  removeHead(d);
            else if (place >= size())
                  removeEnd(d);
            else {
                  auto it = begin();
                  while (place--)
                        it++;
                  erase(it);
            }
      }
      void removeData(const data_type& d) {
            auto it = begin();
            while (*it != d && it != end())
                  it++;
            if (it == end())
                  return;
            erase(it);
      }

    public:
      /*!
       * Init and delete
       */

      // empty cons
      LinkedList() {
            init();
      }

      // one data cons
      LinkedList(const data_type& d) {
            init();
            insertEnd(d);
      }

      // array cons
      template <size_t size>
      LinkedList(data_type (&arr)[size]) {
            init();
            for (size_t i = 0; i < size; i++)
                  insertEnd(arr[i]);
      }
      LinkedList(data_type* arr, size_t size) {
            init();
            for (size_t i = 0; i < size; i++)
                  insertEnd(arr[i]);
      }

      // copy cons
      LinkedList(const LinkedList& l) {
            init();
            for (auto& x : l)
                  insertEnd(x);
      }

      // operator=
      LinkedList& operator=(const LinkedList& l) {
            clear();
            for (auto& x : l)
                  insertEnd(x);
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


      /*!
       * Use the list
       */

      void random(size_t size) {
            clear();
            while (size--)
                  insertEnd(rand() % 100 + 1);
      }

      size_t size() const {
            return _size;
      }

      bool isEmpty() const {
            return _size == 0;
      }

      void clear() {
            while (!isEmpty())
                  removeHead();
      }

      data_type& operator[](size_t index) {
            if (index < 0 || index >= _size)
                  throw "Index out of range";
            auto it = begin();
            while (index-- > 0)
                  it++;
            return *it;
      }

      const data_type& operator[](size_t index) const {
            if (index < 0 || index >= _size)
                  throw "Index out of range";
            auto it = begin();
            while (index-- > 0)
                  it++;
            return *it;
      }

      friend std::ostream&
         operator<<(std::ostream& o, const LinkedList<data_type>& l) {
            for (auto it = l.begin(); it != l.end(); it++)
                  o << *it << " --> ";
            o << " NULL";
            return o;
      }

      data_type sum() {
            data_type sum = data_type();
            for (auto& x : (*this))
                  sum += x;
            return sum;
      }
};
}    // namespace book
#endif