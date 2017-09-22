#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <LinkedList.h>
#include <iostream>
#include <cmath>

namespace data
{
template <class data_type>
class Polynomial : public data::LinkedList<data_type> {
    public:
      Polynomial() : data::LinkedList<data_type>() {}

      template <int size>
      Polynomial(data_type (&List)[size]) : data::LinkedList<data_type>(List) {}
      Polynomial(data_type* List, int size)
          : data::LinkedList<data_type>(List, size) {}

      ~Polynomial() {}

      friend std::ostream&
         operator<<(std::ostream& o, const Polynomial<data_type>& p) {
            int size = p.size();
            if (size == 0) {
                  o << "0";
                  return o;
            }

            o << p.back();
            if (size == 1)
                  return o;
            o << "x";
            if (size >= 2)
                  o << "^" << --size;

            while (--size > -1) {
                  int&      power = size;
                  data_type data  = p[size];

                  if (data == 0)
                        continue;

                  if (data < 0)
                        o << " - ";
                  else
                        o << " + ";

                  if (abs(data) == 1) {
                        if (power == 0)
                              o << 1;
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

      /*!
       * Evaluate with x
       */
      double eval(double x) {
            double sum      = 0;
            double exponent = 0;
            for (auto& p : (*this))
                  sum += p * pow(x, exponent);
            return sum;
      }

      /*!
       * Math on Polynomial
       */
      Polynomial<data_type>& operator+=(const Polynomial<data_type>& p) {
            Polynomial<data_type>* out = new Polynomial<data_type>();
            int max = this->size() > p.size() ? this->size() : p.size();

            while (out->size() < max)
                  out->insertEnd((*this)[out->size()] + p[out->size()]);
            return *out;
      }
      const Polynomial<data_type>
         operator+(const Polynomial<data_type>& p) const {
            return Polynomial(*this) += p;
      }

      Polynomial<data_type>& operator-=(const Polynomial<data_type>& p) {
            Polynomial<data_type>* out = new Polynomial<data_type>();
            int max = this->size() > p.size() ? this->size() : p.size();

            while (out->size() < max)
                  out->insertEnd((*this)[out->size()] - p[out->size()]);
            return *out;
      }
      const Polynomial<data_type>
         operator-(const Polynomial<data_type>& p) const {
            return Polynomial(*this) -= p;
      }

      Polynomial<data_type>& operator*=(const Polynomial<data_type>& p) {
            Polynomial<data_type>* out = new Polynomial<data_type>();
            for (int i = 0; i < p.size() + this->size() - 1; i++)
                  out->insertEnd(0);

            for (int i = 0; i < p.size(); i++)
                  for (int j = 0; j < this->size(); j++)
                        (*out)[i + j] += p[i] * (*this)[j];
            return *out;
      }
      const Polynomial<data_type>
         operator*(const Polynomial<data_type>& p) const {
            return Polynomial(*this) *= p;
      }
};
}    // namespace data

#endif