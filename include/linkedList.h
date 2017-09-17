#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace data
{

template <class T>
struct node
{
      typedef T data_type;
      data_type _data;
      node*     _next;

      node(const data_type& t) : _data(t), _next(NULL) {}
};


template <class T>
class LinkedList {
      typedef T data_type;

    protected:
      int              _size = 0;
      node<data_type>* _head = NULL;

      //
      // ─── COMMON FUNCTION
      // ────────────────────────────────────────────────────────────
      //

    public:
      int size() const {
            return _size;
      }

      bool isEmpty() const {
            return _size == 0;
      }

      node<data_type>* tail() const {
            node<data_type>* tail = _head;
            if (tail != NULL)
                  while (tail->_next != NULL)
                        tail = tail->_next;
            return tail;
      }

      node<data_type>* head() const {
            return _head;
      }

      node<data_type>* getNode(int place) const {
            if (place >= _size)
                  return NULL;
            node<data_type>* returnNode = _head;
            for (int i = 0; i < place; i++)
                  returnNode = returnNode->_next;
            return returnNode;
      }

      data_type& operator[](int place) {
            return getNode(place)->_data;
      }

      const data_type& operator[](int place) const {
            return getNode(place)->_data;
      }

      friend std::ostream& operator<<(std::ostream& o, const LinkedList& l) {
            node<data_type>* runNode = l.head();    // get head
            if (runNode == NULL) {
                  o << "NULL";
                  return o;
            }
            while (runNode->_next != NULL) {
                  o << runNode->_data << " --> ";
                  runNode = runNode->_next;
            }
            o << runNode->_data << " --> NULL";
            return o;
      }

      void printReverse() {
            if (_size == 0)
                  return;
            std::cout << "NULL <-- ";
            for (int i = _size - 1; i > 0; i--)
                  std::cout << getNode(i)->_data << " <-- ";
            std::cout << _head->_data << std::endl;
      }

      //
      // ─── INIT FUNCTION
      // ──────────────────────────────────────────────────────────────
      //

    public:
      LinkedList() {
            _size = 0;
            _head = NULL;
      }

      LinkedList(data_type* List, int size) {
            _size = 0;
            _head = NULL;
            while (size--)
                  insertHead(List[size]);
      }

      LinkedList(const data_type& d) {
            _size = 0;
            _head = NULL;
            insertEnd(d);
      }

      LinkedList(const LinkedList<data_type>& l) {
            while (_size < l.size())
                  insertEnd(l[_size]);
      }

      LinkedList<T>& operator=(const LinkedList<data_type>& l) {
            this->~LinkedList();
            LinkedList<data_type>* result = new LinkedList<T>(l);
            return *result;
      }

      virtual ~LinkedList() {
            while (_size > 0)
                  removeEnd();
      }


      //
      // ─── INSERT
      // ─────────────────────────────────────────────────────────────────────
      //

    protected:
      // to be inherited
      // insertHead & insertAfter & insertEnd
      // is to be redefined
      // doubly linkedlist is different from this
      virtual void insert(node<data_type>* preNode, node<data_type>* newNode) {
            if (preNode == _head || isEmpty()) {
                  // head and empty
                  newNode->_next = _head;
                  _head          = newNode;
            }
            else {
                  // middle and last
                  newNode->_next = preNode->_next;
                  preNode->_next = newNode;
            }
            _size++;
      }

      virtual void insertHead(node<data_type>* newNode) {
            insert(_head, newNode);
      }


      virtual void insertAfter(node<data_type>* newNode, int place) {
            if (place >= _size)
                  return;
            insert(getNode(place), newNode);
      }


      virtual void insertEnd(node<data_type>* newNode) {
            if (_size == 1) {
                  // after head
                  // insert(_head) add new head
                  _head->_next = newNode;
                  _size++;
            }
            else
                  insert(tail(), newNode);
      }

    public:
      void insertHead(const data_type& t) {
            insertHead(new node<data_type>(t));
      }
      void insertAfter(const data_type& t, int place) {
            insertAfter(new node<data_type>(t), place);
      }

      void insertEnd(const data_type& t) {
            insertEnd(new node<data_type>(t));
      }
      //
      // ─── REMOVE
      // ─────────────────────────────────────────────────────────────────────
      //

    protected:
      virtual void remove(node<data_type>* preNode) {
            node<data_type>* removeThis = preNode->_next;
            preNode->_next              = removeThis->_next;
            removeThis->_next           = NULL;
            delete removeThis;
            _size--;
      }

    public:
      virtual void removeHead() {
            if (_size == 0)
                  return;
            else if (_size == 1) {
                  delete _head;
                  _head = NULL;
            }
            else {
                  node<data_type>* removeThis = _head;
                  _head                       = removeThis->_next;
                  removeThis->_next           = NULL;
                  delete removeThis;
            }
            _size--;
      }
      virtual void removeEnd() {
            if (_size == 0)
                  return;
            else if (_size == 1) {
                  removeHead();
                  return;
            }
            node<data_type>* preNode = getNode(_size - 2);
            remove(preNode);
      }
      virtual void removeAfter(int place) {
            if (place < 0 || place >= _size)
                  return;
            if (place == 0)
                  return removeHead();
            if (place == _size - 1)
                  return removeEnd();
            return remove(getNode(place));
      }


      //
      // ─── SWAP
      // ────────────────────────────────────────────────────────────────────
      //

    protected:
      void swap(node<data_type>* in1, node<data_type>* in2) {
            data_type temp = in1->_data;
            in1->_data     = in2->_data;
            in2->_data     = temp;
      }

    public:
      void swap(int in1, int in2) {
            if (in1 < 0 || in1 >= _size)
                  return;
            if (in2 < 0 || in2 >= _size)
                  return;
            swap(getNode(in1), getNode(in2));
      }


      //
      // ─── REPLACE
      // ────────────────────────────────────────────────────────────────────
      //

    protected:
      void replace(node<data_type>* preNode, node<data_type>* newNode) {
            node<data_type>* replaceThis = preNode->_next;
            preNode->_next               = newNode;
            newNode->_next               = replaceThis->_next;
            replaceThis->_next           = NULL;
            delete replaceThis;
      }

    public:
      virtual void replace(int place, node<data_type>* newNode) {
            if (place < 0 || place >= _size)
                  return;
            if (place == 0) {
                  removeHead();
                  insertHead(newNode);
            }
            replace(getNode(place - 1), newNode);
      }

      //
      // ─── SUPPORT FUNCTION
      // ───────────────────────────────────────────────────────────
      //

    public:
      void sort() {
            if (_size <= 1)
                  return;
            // selection sort
            for (int i = 0; i < _size - 1; i++) {
                  int minPlace = i;
                  for (int j = i + 1; j < _size; j++) {
                        if ((*this)[j] < (*this)[minPlace])
                              minPlace = j;
                  }
                  if (minPlace != i)
                        swap(i, minPlace);
            }
      }
};
}    // namespace week2
#endif