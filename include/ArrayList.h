#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

namespace data
{
template <class data_type>
class ArrayList {
    public:
      typedef int              size_t;
      typedef data_type*       iterator;
      typedef const data_type* const_iterator;
      // fixed allocation size
      static const int FREE_SIZE = 16;

    protected:
      size_t     _size;
      size_t     _capacity;
      data_type* _data;


    public:
      size_t size() const {
            return _size;
      }

      size_t capacity() const {
            return _capacity;
      }

      data_type& operator[](size_t index) {
            return _data[index];
      }
      const data_type& operator[](size_t index) const {
            return _data[index];
      }

      bool isEmpty() const {
            return _size == 0;
      }

      bool isFull() const {
            return _size == _capacity;
      }

      void clear() {
            _size     = 0;
            _capacity = FREE_SIZE;
            delete[] _data;
            _data = new data_type[_capacity];
      }

      friend std::ostream& operator<<(std::ostream& o, const ArrayList& a) {
            if (a.isEmpty())
                  return o;
            for (int i = 0; i < a.size() - 1; i++)
                  o << a[i] << ", ";
            o << a.back() << ".";
            return o;
      }

    public:
      ArrayList() : _size(0), _capacity(FREE_SIZE) {
            _data = new data_type[_capacity];
      }

      ArrayList(size_t size) : _size(size), _capacity(size + FREE_SIZE) {
            _data = new data_type[_capacity];
      }

      ArrayList(const ArrayList& a) : _size(a._size), _capacity(a._capacity) {
            _data = new data_type[_capacity];
            for (size_t i  = 0; i < _size; i++)
                  _data[i] = a._data[i];
      }
      ArrayList& operator=(const ArrayList& a) {
            _size     = a.size();
            _capacity = a.capacity();
            delete[] _data;
            _data = new data_type[_capacity];
            for (size_t i = 0; i < _size; i++)
                  _data = a[i];
            return *this;
      }

      template <size_t size>
      ArrayList(data_type (&arr)[size]) {
            _size     = size;
            _capacity = size + FREE_SIZE;
            _data     = new data_type[_capacity];
            for (size_t i  = 0; i < _size; i++)
                  _data[i] = arr[i];
      }
      ArrayList(data_type* arr, size_t size) {
            _size     = size;
            _capacity = size + FREE_SIZE;
            _data     = new data_type[_capacity];
            for (size_t i  = 0; i < _size; i++)
                  _data[i] = arr[i];
      }

      ~ArrayList() {
            delete[] _data;
            _data = NULL;
      }


      void resize(size_t newSize) {
            if (newSize < _capacity)
                  reserve(newSize * 2);
            _size = newSize;
      }
      void reserve(size_t newCapacity) {
            if (newCapacity < _size)
                  return;

            data_type* temp = new data_type[newCapacity];
            for (size_t i = 0; i < _size; i++)
                  temp[i] = _data[i];

            delete[] _data;
            _data     = temp;
            temp      = NULL;
            _capacity = newCapacity;
      }


      void push_back(const data_type& d) {
            if (isFull())
                  reserve(2 * _capacity + 1);
            _data[_size++] = d;
      }

      void pop_back() {
            _size--;
      }

      const data_type& back() const {
            return _data[_size - 1];
      }


      iterator begin() {
            return &_data[0];
      }
      const_iterator begin() const {
            return &_data[0];
      }

      iterator end() {
            return &_data[_size];
      }
      const_iterator end() const {
            return &_data[_size];
      }
};
}

#endif