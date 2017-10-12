#include <test1.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

namespace test1
{
namespace prepare
{}    // namespace prepare
namespace L02
{
      void question1a(int size = 0, int space = 0) {
            if (size == 0)
                  return;
            for (int i = 0; i < space; ++i)
                  cout << "  ";
            for (int i = 0; i < size; ++i)
                  cout << "* ";
            cout << endl;
            question1a(size - 1, space + 1);
      }
      void question1b(int size = 0, int num = 1) {
            if (size == 0)
                  return;
            for (int i = 0; i < size - 1; ++i)
                  cout << "* ";
            for (int i = 0; i < num; ++i)
                  cout << num - i << " ";
            cout << endl;
            question1b(size - 1, num + 1);
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
      void Test() {
            question1a(3);
            question1a(6);
            question1b(3);
            question1b(6);

            LinkedListTest();
            StackTest();

            reverseTest();
      }
}    // namespace L02
namespace L01
{
      void Test() {}
}    // namespace L01
}    // namespace test1