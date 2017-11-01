#include <tut6lab.h>
#include <AVL.h>

namespace week6
{
namespace lab
{
      void labTest() {
            data::AVL<int>* tree = new data::AVL<int>();
            tree->insert(32);
            tree->insert(73);
            tree->insert(62);
            tree->insert(29);
            tree->insert(79);
            tree->insert(26);
            tree->insert(67);
            tree->insert(70);
            tree->insert(43);
            tree->insert(27);
            tree->insert(4);
            tree->insert(46);
            tree->insert(7);
            tree->insert(74);
            tree->insert(5);

            tree->remove(73);
            tree->remove(43);
            tree->remove(62);
            tree->remove(26);
            tree->remove(29);
            tree->remove(5);

            data::SinglyLinkedList<int*>* searchList = tree->search(26);

            for (int* result : *searchList) {
                  std::cout << result << std::endl;
            }

            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);

            delete searchList;
            searchList = tree->search(79);

            // this should print 7 lines
            // with different address
            for (int* result : *searchList) {
                  std::cout << result << std::endl;
            }

            delete searchList;
            searchList = NULL;
      }
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week6
