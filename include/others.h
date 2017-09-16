#ifndef OTHERS_H
#define OTHERS_H

#include <iostream>
#include <string>

int baseCheck(const int& left, const int& right, const std::string& result) {
      int decimal = left * right;
      {
            bool letter = [result]() -> bool {
                  for (char c : result)
                        if (c >= 'a' && c <= 'z')
                              return true;
                  return false;
            }();
            if (!letter) {
                  if (decimal == stoi(result))
                        return 10;
            }
      }

      auto changeBase = [decimal](int base) -> std::string {
            std::string hex = "0123456789ABCDEF";
            int         dec = decimal;
            std::string out = "";
            while (dec != 0) {
                  out = hex[dec % base] + out;
                  dec /= base;
            }
            return out;
      };

      for (int i = 2; i < 17; i++) {
            if (i == 10)
                  continue;
            if (changeBase(i) == result)
                  return i;
      }
      return 0;
}

#endif