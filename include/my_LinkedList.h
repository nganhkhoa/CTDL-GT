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
            return _tail;
      }

      node* end() {
            return _tail;
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
            return getNode(place)->data;
      }

      const data_type& operator[](size_t place) const {
            return getNode(place)->data;
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
            }
            o << "NULL";
            return o;
      }

      void printReverse() {
            if (size() == 0)
                  return;
            std::cout << "NULL <-- ";
            for (int i = size() - 1; i > 0; i--)
                  std::cout << getNode(i)->data << " <-- ";
            std::cout << begin()->data << std::endl;
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
            while (this->size() != size)
                  insertHead(List[this->size()]);
      }

      LinkedList(const data_type& d) {
            init();
            insertEnd(d);
      }

      LinkedList(const LinkedList<data_type>& l) {
            init();
            while (this->size() < l.size())
                  insertEnd(l[this->size()]);
      }

      LinkedList<data_type>& operator=(const LinkedList<data_type>& l) {
            clear();
            while (this->size() < l.size())
                  insertEnd(l[this->size()]);
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

            // set tail->prev to newNode
            if (newNode->next == _tail)
                  _tail->prev = newNode;

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
            // [n] -> new -> [_tail] -> NULL
            //         ^~~~~~~~<|
            insert(_tail->prev, new node(d));
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
            if (place == size() - 1)
                  removeEnd();
            else if (place == 0)
                  removeHead();
            else
                  remove(getNode(place - 1));
      }

      //
      // ─── SUPPORT FUNCTION
      // ───────────────────────────────────────────────────────────
      //

      void swap(node* lhs, node* rhs) {
            data_type temp = lhs->data;
            lhs->data      = rhs->data;
            rhs->data      = temp;
      }

      void sort() {
            if (size() <= 1)
                  return;
            // selection sort
            for (int i = 0; i < size() - 1; i++) {
                  int minPlace = i;
                  for (int j = i + 1; j < size(); j++) {
                        if ((*this)[j] < (*this)[minPlace])
                              minPlace = j;
                  }
                  if (minPlace != i)
                        swap(getNode(i), getNode(minPlace));
            }
      }
};
}    // namespace data
#endif