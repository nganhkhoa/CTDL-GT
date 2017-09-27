#include <tut3lab.h>
#include <Polynomial.h>

#include <iostream>
#include <map>

namespace week3
{
namespace lab
{
      void PolynomialTest() {
            data::Polynomial<int>* poly = new data::Polynomial<int>();
            poly->random(10);
            double x = 1;
            std::cout << *poly << " = " << poly->eval(x) << " (x = " << x << ")"
                      << std::endl;
      }
      void StudentTest() {
            Student List[3] = {Student("1613232", "Trinh Thi Thu Thao", 10, 10),
                               Student("1611617", "Nguyen Anh Khoa", 10, 10),
                               Student("1611657", "Nguyen Minh Khoi", 10, 10)};
            StudentList* BestStudent = new StudentList(List);
            std::cout << *BestStudent << std::endl;
      }
      void LinkedListTest() {
            int                    list[5] = {9, 1, 12, 5, 8};
            data::LinkedList<int>* List    = new data::LinkedList<int>(list);
            List->insertAt(4, 3);
            std::cout << *List << std::endl;
            List->removeData(12);
            std::cout << *List << std::endl;
      }

      node* ReverseNode(node* root, int& n) {
            if (root == NULL)
                  return NULL;
            if (root->next == NULL || n == 0)
                  return root;

            int   newN       = n - 1;
            node* returnNode = ReverseNode(root->next, newN);

            root->next->next = root;
            root->next       = NULL;

            return returnNode;
      }

      void Print(node* head) {
            node* temp = head;
            while (temp != NULL) {
                  std::cout << temp->data << " --> ";
                  temp = temp->next;
            }
            std::cout << "NULL\n";
      }

      void ReverseNodeTest() {
            node* head =
               new node(0, new node(1, new node(2, new node(3, new node(4)))));
            Print(head);
            int size = 5;
            head     = ReverseNode(head, size);
            Print(head);
      }


      void labTest() {
            PolynomialTest();
            StudentTest();
            LinkedListTest();
            ReverseNodeTest();
      }
}    // namespace lab
namespace tut
{
      void printCircle(node* head) {
            node* temp = head;

            if (temp == NULL)
                  return;
            std::cout << temp->data << " --> ";
            temp = temp->next;
            while (temp != head) {
                  std::cout << temp->data << " --> ";
                  temp = temp->next;
            }
            std::cout << "HEAD\n";
      }

      template <int size>
      void          printAddress(int (&arr)[size]) {
            for (int i = 0; i < size; i++)
                  std::cout << arr + i << " ";
            std::cout << std::endl;
      }

      void printAddress(node* head, int size) {
            node* temp = head;
            while (size-- && temp != NULL) {
                  std::cout << temp << " ";
                  temp = temp->next;
            }
      }

      void countValue(node* head, int size) {
            std::map<int, int> value;
            node* temp = head;

            while (temp != NULL && size--) {
                  if (value.find(temp->data) == value.end()) {
                        std::pair<int, int> data(temp->data, 1);
                        value.insert(value.end(), data);
                  }
                  else {
                        value[temp->data] += 1;
                  }
                  temp = temp->next;
            }

            std::cout << "Number of occurrences\n";
            for (auto it = value.begin(); it != value.end(); ++it) {
                  std::cout << (*it).first << ":\t " << (*it).second
                            << std::endl;
            }
      }

      void countValue2(node* head, int size) {
            struct OccurrenceNode
            {
                  int             data;
                  int             occurrence;
                  OccurrenceNode* next;

                  OccurrenceNode(int d) : data(d), occurrence(1), next(NULL) {}
            };

            OccurrenceNode* ans = NULL;

            auto find = [&ans](int d) -> OccurrenceNode* {
                  if (ans == NULL)
                        return NULL;
                  OccurrenceNode* temp = ans;
                  while (temp != NULL) {
                        if (temp->data == d)
                              return temp;
                        temp = temp->next;
                  }
                  return NULL;
            };

            node* temp = head;
            while (temp != NULL && size--) {
                  OccurrenceNode* Found = find(temp->data);
                  if (Found == NULL) {
                        // insert head to ans
                        OccurrenceNode* newNode =
                           new OccurrenceNode(temp->data);
                        newNode->next = ans;
                        ans           = newNode;
                  }
                  else {
                        // add in to Occurrence
                        Found->occurrence++;
                  }
                  temp = temp->next;
            }

            OccurrenceNode* toPrint = ans;
            while (toPrint != NULL) {
                  std::cout << toPrint->data << ":\t" << toPrint->occurrence
                            << "\n";
                  toPrint = toPrint->next;
            }
      }

      void nodeTest() {
            node* head = new node(0, new node(1, new node(2, new node(3))));
            head->next->next->next->next = head;
            printCircle(head);
            node* head2 = new node(
               9, new node(1, new node(12, new node(6, new node(12)))));
            std::cout << "Using map count\n";
            countValue(head2, 5);
            std::cout << "Using Linked List count\n";
            countValue2(head2, 5);
      }

      void compareList() {
            int   arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            node* head    = new node(
               0,
               new node(
                  1,
                  new node(
                     2,
                     new node(
                        3,
                        new node(
                           4,
                           new node(
                              5,
                              new node(
                                 6,
                                 new node(7, new node(8, new node(9))))))))));

            printAddress(arr);
            printAddress(head, 10);
      }

      void tutTest() {
            /**
             *  Problem 1
             * O(n)
             * When don't know the capacity
             * When know that data never biger then...
             */

            /**
             *  Problem 5
             * Array address is relative to the first
             * LinkedList address is random
             */

            nodeTest();
            compareList();
      }
}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week3