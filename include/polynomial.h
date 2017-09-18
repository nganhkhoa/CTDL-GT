#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <linkedList.h>
#include <iostream>

namespace data
{
template <class T>
class Polynomial : public data::LinkedList<T> {
    public:
      Polynomial() : data::LinkedList<T>() {}

      template <int size>
      Polynomial(T (&List)[size]) : data::LinkedList<T>(List) {}

      Polynomial(T* List, int size) : data::LinkedList<T>(List, size) {}
      ~Polynomial() {}

      friend std::ostream& operator<<(std::ostream& o, const Polynomial<T>& p) {
            int size = p.size();
            if (size == 0) {
                  o << "0";
                  return o;
            }

            o << p.tail()->_data;
            if (size == 1)
                  return o;
            o << "x";
            if (size >= 2)
                  o << "^" << --size;

            data::node<T>* runNode = NULL;
            while (size > 0) {
                  runNode    = p.getNode(--size);    // size is now power
                  int& power = size;
                  T&   data  = runNode->_data;

                  if (data == 0)
                        continue;

                  if (data < 0)
                        o << " - ";
                  else
                        o << " + ";

                  if (abs(data) == 1) {
                        if (power == 0)
                              continue;
                        else if (power == 1)
                              o << "x";
                        else
                              o << "x^" << power;
                  }
                  else {
                        if (power == 0)
                              o << abs(data);
                        else if (power == 1)
                              o << abs(data) << "x";
                        else
                              o << abs(data) << "x^" << power;
                  }
            }
            return o;
      }

      Polynomial<T>& operator+=(const Polynomial<T>& p) {
            Polynomial<T>* out = new Polynomial<T>();
            int max = this->size() > p.size() ? this->size() : p.size();

            while (out->size() < max)
                  out->insertEnd((*this)[out->size()] + p[out->size()]);
            return *out;
      }
      const Polynomial<T> operator+(const Polynomial<T>& p) const {
            return Polynomial(*this) += p;
      }

      Polynomial<T>& operator-=(const Polynomial<T>& p) {
            Polynomial<T>* out = new Polynomial<T>();
            int max = this->size() > p.size() ? this->size() : p.size();

            while (out->size() < max)
                  out->insertEnd((*this)[out->size()] - p[out->size()]);
            return *out;
      }
      const Polynomial<T> operator-(const Polynomial<T>& p) const {
            return Polynomial(*this) -= p;
      }

      Polynomial<T>& operator*=(const Polynomial<T>& p) {
            Polynomial<T>* out = new Polynomial<T>();
            for (int i = 0; i < p.size() + this->size() - 1; i++)
                  out->insertEnd(0);

            for (int i = 0; i < p.size(); i++)
                  for (int j = 0; j < this->size(); j++)
                        (*out)[i + j] += p[i] * (*this)[j];
            return *out;
      }
      const Polynomial<T> operator*(const Polynomial<T>& p) const {
            return Polynomial(*this) *= p;
      }
};
}    // namespace data

#endif