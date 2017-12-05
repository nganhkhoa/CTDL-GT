#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <array>

namespace data
{
// General Implement of Hash
template <class data_type, size_t capacity>
class Hash {
    protected:
      struct item
      {
            data_type data;
            bool      empty;

            item(data_type& d) : data(d) {
                  empty = false;
            }

            inline bool isEmpty() const {
                  return empty;
            }
      };
      std::array<item, capacity> hash;

      void AddToHash(struct item& i, size_t& idx) {}

    public:
      Hash() {}
      ~Hash() {}
      virtual void insert(data_type& d) = 0;
      virtual void remove(data_type& d) = 0;
};

// Hash with specific function
template <
   class data_type,
   size_t capacity,
   size_t (*func)(const data_type&, size_t&)>
class HashFunction : Hash<data_type, capacity> {
      size_t (*hashFunction)(const data_type&, size_t&);

    public:
      HashFunction() {
            hashFunction = func;
      }

      ~HashFunction() {}

      void insert(data_type& d) {
            size_t      idx = hashFunction(d, capacity);
            struct item newItem(d);
            AddToHash(newItem, idx);
      }
};
}
#endif