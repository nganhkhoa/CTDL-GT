#include "[1611617]Question1.h"

#include <iostream>

using std::cout;
using std::endl;


void question1a(int size, int space) {
      if (size == 0)
            return;
      for (int i = 0; i < space; ++i)
            cout << "  ";
      for (int i = 0; i < size; ++i)
            cout << "* ";
      cout << endl;
      question1a(size - 1, space + 1);
}