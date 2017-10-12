#include <iostream>

#include "[1611617]Question1.h"
#include "[1611617]LinkedList.h"
#include "[1611617]Stack.h"

void LinkedListTest();
void StackTest();
void reverseTest();

using std::cout;
using std::endl;

int main(int argv, char** argc) {
      question1a(3);
      question1a(6);
      question1b(3);
      question1b(6);

      LinkedListTest();
      StackTest();

      reverseTest();
      return 0;
}

void LinkedListTest() {
      LinkedList* list = new LinkedList();
      list->insertAt(1, 1);
      list->insertAt(2, 2);
      list->insertAt(3, 3);
      cout << *list << endl;

      list->removeAt(2);
      cout << *list << endl;
}

void StackTest() {
      Stack* stack = new Stack();
      stack->push(1);
      stack->push(2);
      stack->push(3);
      stack->push(4);
      stack->pop();
      cout << *stack << endl;
}

void reverseTest() {
      LinkedList* list = new LinkedList();
      list->insertAt(1, 1);
      list->insertAt(2, 2);
      list->insertAt(3, 3);

      list->reverse_using_stack();
      cout << *list << endl;

      list->reverse_using_queue();
      cout << *list << endl;
}