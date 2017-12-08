#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <array>

namespace data
{
// General Implement of Hash
template <class data_type, size_t cap>
class Hash {
    protected:
      struct item
      {
            data_type data;
            bool      empty;

            item() : data() {
                  empty = true;
            }

            inline bool isEmpty() const {
                  return empty;
            }

            inline void makeEmpty() {
                  empty = false;
            }

            void fill(const data_type& d) {
                  data  = d;
                  empty = false;
            }
      };

      std::array<item, cap> hash;
      size_t                size;
      size_t                _capacity;

      void AddToHash(const data_type& d, size_t& idx) {
            while (true) {
                  if (hash[idx].isEmpty()) {
                        hash[idx].fill(d);
                        size++;
                        return;
                  }
                  else if (isFull()) {
                        hash[idx].fill(d);
                        return;
                  }
                  else
                        fixCollision(idx);
            }
      }

      // abstract class so make cons hidden
      Hash() {
            size = 0;
      }

    public:
      ~Hash() {}

      inline bool isFull() const {
            return size == capacity();
      }

      inline bool isEmpty() const {
            return size == 0;
      }

      inline size_t capacity() const {
            return _capacity;
      }

      virtual void insert(const data_type& d) = 0;
      virtual void fixCollision(size_t& idx) {
            if (++idx == capacity())
                  idx = 0;
      }

      void remove(const data_type& d) {
            for (auto& item : hash) {
                  if (item.data != d)
                        continue;
                  item.makeEmpty();
                  return;
            }
      }

      void remove(const size_t& idx) {
            if (idx < 0 || idx >= capacity())
                  return;
            hash[idx].makeEmpty();
      }

      friend std::ostream& operator<<(std::ostream& o, const Hash& h) {
            if (h.isEmpty()) {
                  o << "empty";
                  return o;
            }
            for (auto& x : h.hash)
                  if (!x.isEmpty())
                        o << x.data << " ";
            return o;
      }
};

template <class data_type>
size_t sampleHash(const data_type& d, const size_t& cap) {
      // sample mod hash
      return d % cap;
}

// Hash with specific function
template <
   class data_type,
   size_t cap                                      = 10,
   size_t (*func)(const data_type&, const size_t&) = nullptr>
class HashFunction : public Hash<data_type, cap> {
      size_t (*hashFunction)(const data_type&, const size_t&);

    public:
      HashFunction() {
            if (func != nullptr)
                  hashFunction = func;
            else
                  hashFunction = sampleHash;
      }

      ~HashFunction() {}

      void insert(const data_type& d) {
            size_t idx = hashFunction(d, cap);
            this->AddToHash(d, idx);
      }
};
}
#endif