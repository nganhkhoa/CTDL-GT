#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

namespace data
{
class Coordinate {
      double _x;
      double _y;
      double _z;

    public:
      Coordinate() : _x(0), _y(0), _z(0) {}
      Coordinate(double x, double y) : _x(x), _y(y), _z(0) {}
      Coordinate(double x, double y, double z) : _x(x), _y(y), _z(z) {}
      Coordinate(const Coordinate& c) : _x(c._x), _y(c._y), _z(c._z) {}

      double x() const {
            return _x;
      }

      double y() const {
            return _y;
      }

      double z() const {
            return _z;
      }

      friend std::ostream& operator<<(std::ostream& o, const Coordinate& c) {
            o << "(" << c.x() << ", " << c.y() << ", " << c.z() << ")";
            return o;
      }

      Coordinate& operator+=(const Coordinate& c) {
            Coordinate* out = new Coordinate(
               c._x + this->_x, c._y + this->_y, c._z + this->_z);
            return *out;
      }
      const Coordinate operator+(const Coordinate& c) const {
            return Coordinate(*this) += c;
      }

      Coordinate& operator-=(const Coordinate& c) {
            Coordinate* out = new Coordinate(
               this->_x - c._x, this->_y - c._y, this->_z - c._z);
            return *out;
      }
      const Coordinate operator-(const Coordinate& c) const {
            return Coordinate(*this) -= c;
      }
};

const Coordinate i_vector(1, 0, 0);
const Coordinate j_vector(0, 1, 0);
const Coordinate k_vector(0, 0, 1);
}    // namespace data
#endif