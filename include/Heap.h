#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <array>

namespace data
{
template <class data_type, size_t capacity = 10, bool max = true>
class Heap {

      /// Data
      std::array<data_type, capacity + 1> heap;
      size_t _size;

      bool (*validate)(data_type&, data_type&);
      data_type& (*compare)(data_type&, data_type&);
      /// END Data

      /// Min Max Functions
      static data_type& getMax(data_type& lhs, data_type& rhs) {
            return lhs > rhs ? lhs : rhs;
      }
      static data_type& getMin(data_type& lhs, data_type& rhs) {
            return lhs < rhs ? lhs : rhs;
      }

      static bool cmp_max(data_type& lhs, data_type& rhs) {
            return lhs > rhs ? true : false;
      }
      static bool cmp_min(data_type& lhs, data_type& rhs) {
            return lhs < rhs ? true : false;
      }
      /// END Min Max Functions

      /// Helpers
      void swap(data_type& lhs, data_type& rhs) {
            data_type temp = lhs;
            lhs            = rhs;
            rhs            = temp;
      }

      void reheapUp(size_t idx) {
            if (idx <= 1)
                  return;

            size_t parent = idx / 2;

            if (!validate(heap[parent], heap[idx])) {
                  swap(heap[parent], heap[idx]);
            }

            reheapUp(parent);
      }

      void reheapDown(size_t idx) {
            // bottom or over
            if (idx > size())
                  return;

            size_t leftChild  = idx * 2;
            size_t rightChild = idx * 2 + 1;

            // if both child, get bigger and go there
            if (leftChild <= size() && rightChild <= size()) {
                  swap(heap[idx], compare(heap[leftChild], heap[rightChild]));
                  validate(heap[leftChild], heap[rightChild])
                     ? reheapDown(leftChild)
                     : reheapDown(rightChild);

                  return;
            }

            // if only left child
            if (leftChild <= size()) {
                  if (validate(heap[leftChild], heap[idx]))
                        reheapDown(leftChild);
                  return;
            }

            // if only right child
            if (rightChild <= size()) {
                  if (validate(heap[rightChild], heap[idx]))
                        reheapDown(rightChild);
                  return;
            }

            // if none
      }
      /// END Helpers

    public:
      Heap() {
            _size = 0;
            if (max) {
                  compare  = getMax;
                  validate = cmp_max;
            }
            else {
                  compare  = getMin;
                  validate = cmp_min;
            }
      }

      ~Heap() {
            _size    = 0;
            compare  = nullptr;
            validate = nullptr;
      }

      inline size_t size() const {
            return _size;
      }

      inline bool isEmpty() const {
            return size() == 0;
      }

      inline bool isFull() const {
            return size() == capacity;
      }

      void insert(const data_type& d) {
            _size++;

            if (isFull())
                  return;

            heap[_size] = d;
            reheapUp(_size);
      }

      void remove(const data_type& d) {
            if (isEmpty())
                  return;

            size_t idx = 1;
            for (; idx <= size(); idx++)
                  if (d == heap[idx])
                        break;

            // not found
            if (idx > size())
                  return;

            // swap with bottom elements and delete
            // advoid last data for performance
            if (idx != size())
                  swap(heap[idx], heap[size()]);

            _size--;

            reheapDown(idx);
      }

      friend std::ostream& operator<<(std::ostream& o, const Heap& h) {
            for (size_t i = 1; i <= h.size(); ++i)
                  o << h.heap[i] << " ";
            return o;
      }
};
}
#endif