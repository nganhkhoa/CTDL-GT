#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <coordinate.h>

namespace data
{
template <class T>
class Matrix {

    protected:
      T*  _value;
      int _row;
      int _col;

    public:
      T* value() const {
            return _value;
      }
      int row() const {
            return _row;
      }

      int col() const {
            return _col;
      }

      // top left is (0,0)
      // bottom right (-_col, -_row)
      T& operator[](const Coordinate& c) {
            return _value[(int) (-1 * c.y() * _col + c.x())];
      }
      const T& operator[](const Coordinate& c) const {
            return _value[(int) (-1 * c.y() * _col + c.x())];
      }

      //
      // ─── INIT
      // ───────────────────────────────────────────────────────────────────────
      //

    public:
      Matrix(T* value, int row, int col) : _row(row), _col(col) {
            _value = new T[row * col];
            for (int i      = 0; i < row * col; i++)
                  _value[i] = value[i];
      }

      Matrix(int row, int col) : _row(row), _col(col) {
            _value = new T[row * col];
            for (int i      = 0; i < row * col; i++)
                  _value[i] = 0;
      }

      Matrix() {
            _value = NULL;
            _row   = 0;
            _col   = 0;
      }

      ~Matrix() {
            if (_value != NULL) {
                  delete[] _value;
                  _value = NULL;
            }
            _row = 0;
            _col = 0;
      }

      Matrix(const Matrix<T>& m) {
            _row   = m._row;
            _col   = m._col;
            _value = new T[_row * _col];
            for (int i      = 0; i < _row * _col; i++)
                  _value[i] = m._value[i];
      }

      Matrix<T>& operator=(const Matrix<T>& m) {
            if (_value != NULL) {
                  delete[] _value;
                  _value = NULL;
            }
            _col   = m._col;
            _row   = m._row;
            _value = new T[_row * _col];
            for (int i      = 0; i < _row * _col; i++)
                  _value[i] = m._value[i];
            return *this;
      }

      //
      // ─── MATH ON MATRIX
      // ─────────────────────────────────────────────────────────────
      //


      Matrix<T>& operator*=(const Matrix<T>& m) {
            if (this->_col != m._row)
                  return *(new Matrix<T>());

            // there are many algorithm
            // this is a quick writing
            // so no algorithm implemented
            // And yes I do aware that this is O(n^3)
            int     commonSize = this->_col;
            int     newRow     = this->_row;
            int     newCol     = m._col;
            Matrix* out        = new Matrix<T>(newRow, newCol);
            for (int row = 0; row < newRow; row++)
                  for (int col = 0; col < newCol; col++)
                        for (int i = 0; i < commonSize; i++)
                              out->_value[row * newCol + col] +=
                                 this->_value[row * commonSize + i] *
                                 m._value[i * newCol + col];
            return *out;
      }
      const Matrix operator*(const Matrix<T>& m) const {
            return (Matrix<T>(*this) *= m);
      }

      //
      // ─── COMMON FUNCTION
      // ────────────────────────────────────────────────────────────
      //

      // who doesn't want simple printing?
      friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
            const T* value = m.value();
            if (value == NULL)
                  return out;
            int row = m.row();
            int col = m.col();
            for (int i = 0; i < row; i++) {
                  for (int j = 0; j < col; j++)
                        out << value[i * col + j] << "\t";
                  out << std::endl;
            }
            return out;
      }

      // a method to compare two matrixes
      bool operator==(const Matrix<T>& m) {
            if ((this->_col != m._col) || (this->_row != m._row))
                  return false;

            int      rows      = this->_row;
            int      cols      = this->_col;
            const T* ThisValue = this->_value;
            const T* MValue    = m._value;
            for (int row = 0; row < rows; row++)
                  for (int col = 0; col < cols; col++)
                        if (
                           ThisValue[row * cols + col] !=
                           MValue[row * cols + col])
                              return false;
            return true;
      }
};
}
#endif