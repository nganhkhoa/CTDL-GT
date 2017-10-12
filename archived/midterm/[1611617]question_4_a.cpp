#include "[1611617]LinkedList.h"
#include "[1611617]Stack.h"

void LinkedList::reverse_using_stack() {
      Stack* stack = new Stack(size());

      while (!empty()) {
            stack->push(_head->next->data);
            removeAt(1);
      }

      while (!stack->empty()) {
            insertAt(size() + 1, stack->top());
            stack->pop();
      }
}