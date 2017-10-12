#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
    private:
      struct node
      {
            int   data;
            node* next;
            node(int d = 0, node* n = NULL) : data(d), next(n) {}
      };
      typedef int size_t;
      size_t      capacity;
      size_t      _size;
      node*       _top;

    public:
      Stack(size_t cap = 3) : capacity(cap) {
            _size = 0;
            _top  = NULL;
      }

      inline size_t size() const {
            return _size;
      }

      bool empty();
      bool full();

      bool push(int data);
      bool pop();

      int& top() {
            if (empty()) {
                  std::cout << "Nothing to return\n";
                  return *(new int());
            }
            return _top->data;
      }

      friend std::ostream& operator<<(std::ostream& o, const Stack& s) {
            auto temp = s._top;

            o << "TOP: ";
            while (temp) {
                  o << temp->data;
                  o << " <-- ";
                  temp = temp->next;
            }
            o << "END STACK";
            return o;
      }
};

#endif