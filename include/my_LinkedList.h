#ifndef MY_LINKEDLIST_H
#define MY_LINKEDLIST_H

#include <iostream>

namespace data
{
template <class data_type>
class LinkedList {
      typedef int size_t;

    protected:
      struct node
      {
            data_type data;
            node*     next;
            node*     prev = NULL;

            node(
               const data_type& t = data_type(),
               node*            n = NULL,
               node*            p = NULL)
                : data(t), next(n), prev(p) {}
      };

      size_t _size;
      node*  _head = NULL;
      node*  _tail = NULL;

      virtual void init() {
            // the list: [head] -> [0] -> [1] <-> [tail] -> NULL
            // init: [head] <-> [tail] -> NULL
            // virtual for doubly and circularly
            _head       = new node();
            _tail       = new node();
            _head->next = _tail;
            _tail->next = NULL;
            _tail->prev = _head;
            _size       = 0;
      }

      //
      // ─── COMMON FUNCTION
      // ────────────────────────────────────────────────────────────
      //

    public:
      size_t size() const {
            return _size;
      }

      bool isEmpty() const {
            return _size == 0;
      }

      void clear() {
            while (!isEmpty())
                  removeEnd();
      }


      //
      // ─── RETRIVE
      // ────────────────────────────────────────────────────────────────────
      //

      node* begin() const {
            return _head->next;
      }

      node* begin() {
            return _head->next;
      }

      node* end() const {
            return _tail->prev;
      }

      node* end() {
            return _tail->prev;
      }

      node* getNode(size_t place) {
            node* temp = begin();
            while (place-- > 0)
                  temp = temp->next;
            return temp;
      }

      node* getNode(size_t place) const {
            node* temp = begin();
            while (place-- > 0)
                  temp = temp->next;
            return temp;
      }

      data_type& operator[](size_t place) {
            auto temp = begin();
            while (place-- > 0)
                  temp = temp->next;
            return temp->data;
      }

      data_type& operator[](size_t place) const {
            auto temp = begin();
            while (place-- > 0)
                  temp = temp->next;
            return temp->data;
      }

      friend std::ostream&
         operator<<(std::ostream& o, const LinkedList<data_type>& l) {
            if (!l.isEmpty()) {
                  auto temp = l.begin();
                  auto end  = l.end();
                  while (temp != end) {
                        o << temp->data << " --> ";
                        temp = temp->next;
                  }
                  o << temp->data << " --> ";
            }
            o << "NULL";
            return o;
      }

      //
      // ─── INIT FUNCTION
      // ──────────────────────────────────────────────────────────────
      //

    public:
      LinkedList() {
            init();
      }

      LinkedList(data_type* List, int size) {
            init();
            while (size--)
                  insertHead(List[size]);
      }

      template <int size>
      LinkedList(data_type (&List)[size]) {
            init();
            while (_size != size)
                  insertHead(List[_size]);
      }

      LinkedList(const data_type& d) {
            init();
            insertEnd(d);
      }

      LinkedList(const LinkedList<data_type>& l) {
            init();
            while (_size < l.size())
                  insertEnd(l[_size]);
      }

      LinkedList<data_type>& operator=(const LinkedList<data_type>& l) {
            clear();
            while (_size < l.size())
                  insertEnd(l[_size]);
            return *this;
      }

      virtual ~LinkedList() {
            clear();
            delete _tail;
            _tail = NULL;
            delete _head;
            _head = NULL;
      }

      //
      // ─── INSERT
      // ─────────────────────────────────────────────────────────────────────
      //

    protected:
      virtual void insert(node* prev, node* newNode) {
            newNode->next = prev->next;
            prev->next    = newNode;
            _size++;
      }

    public:
      void insertHead(const data_type& d) {
            if (isEmpty())
                  insertEnd(d);
            else
                  insert(_head, new node(d));
      }

      void insertEnd(const data_type& d) {
            // [n] <-> [_tail] -> NULL
            insert(_tail->prev, new node(d));
            // [n] -> new -> [_tail] -> NULL
            //  ^~~~~~~~~~~~~~~<|
            // but [_tail] -> prev is still [n]
            _tail->prev = _tail->prev->next;
      }

      void insertAt(size_t place, const data_type& d) {
            if (place == 0)
                  insertHead(d);
            else if (place == _size)
                  insertEnd(d);
            else
                  insert(getNode(place - 1), new node(d));
      }

      //
      // ─── REMOVE
      // ─────────────────────────────────────────────────────────────────────
      //

    protected:
      virtual void remove(node* prev) {
            if (isEmpty())
                  return;

            node* removeThis = prev->next;
            prev->next       = prev->next->next;
            removeThis->next = NULL;
            delete removeThis;
            _size--;
      }

    public:
      void removeHead() {
            remove(_head);
            if (_head->next == _tail)
                  _tail->prev = _head;
      }
      void removeEnd() {
            node* end = _head;
            while ((end->next != _tail->prev) && (end->next != _tail))
                  end = end->next;
            remove(end);
            _tail->prev = end;
      }

      void removeAt(size_t place) {
            if (place == 0)
                  removeHead();
            else if (place == _size - 1)
                  removeEnd();
            else
                  remove(getNode(place - 1));
      }

      //
      // ─── SWAP
      // ────────────────────────────────────────────────────────────────────
      //


      //
      // ─── REPLACE
      // ────────────────────────────────────────────────────────────────────
      //


      //
      // ─── SUPPORT FUNCTION
      // ───────────────────────────────────────────────────────────
      //
};
}    // namespace data
#endif