#include <LinkedList.h>
#include <iostream>
namespace book
{
void LinkedListTest() {
      LinkedList<int> List;
      List.push_back(0);
      List.push_back(1);
      List.push_front(-1);
      std::cout << List << std::endl;
}
}