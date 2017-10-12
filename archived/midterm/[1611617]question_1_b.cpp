#include "[1611617]Question1.h"

#include <iostream>

using std::cout;
using std::endl;


void question1b(int size, int num) {
      if (size == 0)
            return;
      for (int i = 0; i < size - 1; ++i)
            cout << "* ";
      for (int i = 0; i < num; ++i)
            cout << num - i << " ";
      cout << endl;
      question1b(size - 1, num + 1);
}