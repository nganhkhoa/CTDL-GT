#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

namespace data
{
template <class data_type>
class SinglyLinkedList {
      typedef int size_t;

      // list
      // [head/tail] -> NULL
      // [head] ->...-> [tail] -> NULL

      // begin return head->next
      // end return tail->next
      // data starts at head->next
      // and ends at tail
    protected:
      struct node
      {
            data_type data;
            node*     next;

            node(data_type d = data_type(), node* n = NULL)
                : data(d), next(n) {}
      };

      size_t _size;
      node*  _head;
      node*  _tail;

      void init() {
            _size = 0;
            _head = new node();
            _tail = _head;
      }

    public:
      SinglyLinkedList() {
            init();
      }
      SinglyLinkedList<data_type>(const SinglyLinkedList<data_type>& l) {
            init();
            for (auto& x : l)
                  insertEnd(x);
      }
      SinglyLinkedList<data_type>&
         operator=(const SinglyLinkedList<data_type>& l) {
            clear();
            for (auto& x : l)
                  insertEnd(x);
      }

    public:
      void clear() {
            while (size())
                  removeHead();
      }
      size_t size() const {
            return _size;
      }
      bool isEmpty() const {
            return size() == 0;
      }

      void insertHead(const data_type& d) {
            if (isEmpty())
                  insertEnd(d);
            else
                  insert({(*this), _head}, d);
      }
      void insertEnd(const data_type& d) {
            _tail->next = new node(d);
            _tail       = _tail->next;
            _size++;
      }
      void insertAt(size_t place, const data_type& d) {
            auto it = begin();
            while (--place)
                  ++it;
            insert(it, d);
      }
      void removeHead() {
            if (isEmpty())
                  return;
            remove({(*this), _head});
            if (isEmpty())
                  _tail = _head;
      }
      void removeEnd() {
            if (isEmpty())
                  return;
            node* temp = _head;
            while (temp->next != _tail)
                  temp = temp->next;
            remove({(*this), temp});
            _tail = temp;
      }
      void removeAt(size_t place) {
            auto it = begin();
            while (--place)
                  ++it;
            remove(it);
      }

    public:
      class const_iterator {
          protected:
            const SinglyLinkedList<data_type>* thisList;
            node*                              current;

            data_type& retrieve() const {
                  return current->data;
            }

            const_iterator(const SinglyLinkedList<data_type>& l, node* n)
                : thisList(&l), current(n) {}

            void valid() {
                  if (0)
                        throw "";
            }

            friend class SinglyLinkedList<data_type>;

          public:
            const_iterator() : current(NULL) {}

            const data_type& operator*() const {
                  return retrieve();
            }

            const_iterator operator++() {
                  current = current->next;
                  return (*this);
            }
            const_iterator operator++(int) {
                  const_iterator old = (*this);
                  ++(*this);
                  return old;
            }
            bool operator==(const const_iterator& c) const {
                  return current == c.current;
            }
            bool operator!=(const const_iterator& c) const {
                  return !((*this) == c);
            }
      };
      class iterator : public const_iterator {
          protected:
            iterator(const SinglyLinkedList<data_type>& l, node* n)
                : const_iterator(l, n) {}

            friend class SinglyLinkedList<data_type>;

          public:
            iterator() {}

            data_type& operator*() {
                  return const_iterator::retrieve();
            }
            const data_type& operator*() const {
                  return const_iterator::retrieve();
            }

            iterator operator++() {
                  this->current = this->current->next;
                  return (*this);
            }
            iterator operator++(int) {
                  iterator old = (*this);
                  ++(*this);
                  return old;
            }
      };

    public:
      iterator begin() {
            return {(*this), _head->next};
      }
      const_iterator begin() const {
            return {(*this), _head->next};
      }
      iterator end() {
            return {(*this), _tail->next};
      }
      const_iterator end() const {
            return {(*this), _tail->next};
      }

      data_type& front() {
            return *begin();
      }
      const data_type& front() const {
            return *begin();
      }
      data_type& back() {
            return *end();
      }
      const data_type& back() const {
            return *end();
      }
      data_type& operator[](size_t place) {
            auto it = begin();
            while (place--)
                  it++;
            return *it;
      }
      const data_type& operator[](size_t place) const {
            auto it = begin();
            while (place--)
                  it++;
            return *it;
      }
      friend std::ostream&
         operator<<(std::ostream& o, const SinglyLinkedList<data_type>& l) {
            for (auto& d : l)
                  o << d << " --> ";
            o << "NULL";
            return o;
      }

    public:
      // insert after it
      iterator insert(iterator it, const data_type& d) {
            node* before = it.current;
            _size++;
            return {(*this), before->next = new node(d, before->next)};
      }
      // remove after it
      iterator remove(iterator it) {
            node* current    = it.current;
            node* removeThis = current->next;
            current->next    = removeThis->next;
            removeThis->next = NULL;
            delete removeThis;
            _size--;
            return it;
      }
      // remove after "from" to before "to"
      iterator remove(iterator from, iterator to) {
            for (auto it = from; it.current->next != to.current;) {
                  it = remove(it);
            }
      }
};
}

#endif