#include <tut2lab.h>
#include <polynomial.h>
#include <linkedList.h>

#include <iostream>

namespace week2
{
namespace lab
{
      void LinkedListTest() {
            int                    List[5] = {5, 8, 3, 2, 9};
            data::LinkedList<int>* intList = new data::LinkedList<int>(List, 5);
            std::cout << *intList << std::endl;
            intList->printReverse();
            intList->sort();
            std::cout << *intList << std::endl;
      }

      void polynomialTest() {
            data::Polynomial<int>* poly1 =
               new data::Polynomial<int>(new int[5]{5, 8, 3, 2, 9}, 5);
            data::Polynomial<int>* poly2 =
               new data::Polynomial<int>(new int[5]{2, 0, 0, 1, 5}, 5);

            std::cout << *poly1 << std::endl;
            std::cout << *poly2 << std::endl;

            std::cout << *poly1 + *poly2 << std::endl;
            std::cout << *poly1 - *poly2 << std::endl;
            std::cout << *poly1 * *poly2 << std::endl;
      }

      int factorial(int n) {
            if (n <= 1)
                  return 1;
            return n * factorial(n - 1);
      }

      int sumDownBy2(int n) {
            if (n <= 0)
                  return 0;
            return n + sumDownBy2(n - 2);
      }

      void secretGardenTest() {
            SecretGarden* gardenOfEden = new SecretGarden(10);
            std::cout << *gardenOfEden << std::endl;
            // gardenOfEden->showAnswer();
            gardenOfEden->shortestPath();
      }

      void labTest() {
            LinkedListTest();
            polynomialTest();
            sumDownBy2(7);
            secretGardenTest();
      }
}    // namespace lab

namespace tut
{
      bool isPrime(int num) {
            if (num < 2)
                  return false;

            for (int i = 2; i * i <= num; i++)
                  if (num % i == 0)
                        return false;
            return true;
      }

      void onePrime(int* arr, int n) {
            if (n == 0)
                  return;
            if (isPrime(*arr)) {
                  std::cout << *arr << " ";
                  return;
            }
            return onePrime(arr + 1, n - 1);
      }

      void allPrime(int* arr, int n) {
            if (n == 0)
                  return;
            if (isPrime(*arr))
                  std::cout << *arr << " ";
            return allPrime(arr + 1, n - 1);
      }

      int Fibonacci(int num) {
            if (num == 0)
                  return 0;
            if (num == 1)
                  return 1;
            return Fibonacci(num - 1) + Fibonacci(num - 2);
      }


      // call myMaxFunc(head, 0);
      int myMaxFunc(node* head, int maxVal) {
            if (head == NULL)
                  return maxVal;
            return myMaxFunc(
               head->next, maxVal > head->data ? maxVal : head->data);
      }

      void insertHead(node*& head, node* newNode) {
            if (head == NULL) {
                  head = newNode;
                  return;
            }
            newNode->next = head;
            head          = newNode;
      }
      void insertHead(node*& head, int value) {
            insertHead(head, new node(value));
      }
      void insertEnd(node* head, node* newNode) {
            node* temp = head;
            while (temp->next != NULL)
                  temp = temp->next;
            temp->next = newNode;
      }
      void insertEnd(node* head, int value) {
            insertEnd(head, new node(value));
      }
      void insertMiddle(node* preNode, node* newNode) {
            if (preNode->next == NULL)
                  preNode->next = newNode;
            else {
                  newNode->next = preNode->next;
                  preNode->next = newNode;
            }
      }
      void insertMiddle(node* preNode, int value) {
            insertMiddle(preNode, new node(value));
      }
      void deleteValue(node*& head, int value) {
            node* temp = head;
            if (temp == NULL)
                  return;

            while (temp->data != value && temp->next != NULL)
                  temp = temp->next;

            if (temp->data == value)
                  deleteNode(head, temp);
      }
      void deleteNode(node*& head, node* thisNode) {
            if (head == thisNode) {
                  head->next = NULL;
                  head       = thisNode->next;
                  return;
            }

            node* temp = head;
            while (temp->next != thisNode && temp->next != NULL) {
                  temp = temp->next;
            }

            if (temp->next == NULL) {
                  std::cout << "Node cannot be found" << std::endl;
                  return;
            }

            temp->next     = thisNode->next;
            thisNode->next = NULL;
            delete thisNode;
      }

      void print(node* head) {
            if (head == NULL)
                  return;
            std::cout << head->data << " ";
            print(head->next);
      }

      void fun1(node* head) {
            if (head == NULL)
                  return;
            fun1(head->next);
            std::cout << head->data << " ";
      }

      void fun2(node* head) {
            if (head == NULL)
                  return;
            std::cout << head->data << " ";
            if (head->next != NULL)
                  fun2(head->next->next);
            std::cout << head->data << " ";
      }

      void func1(node* head) {
            node* temp = head;
            while (temp != NULL) {
                  if (temp->next == NULL) {
                        temp->next = head;
                        return;
                  }
                  temp = temp->next;
            }
      }
      void printCircle(node* head) {
            if (head == NULL)
                  return;
            node* tempNode = head;
            std::cout << tempNode->data << " ";
            tempNode = head->next;
            while (tempNode != head) {
                  std::cout << tempNode->data << " ";
                  tempNode = tempNode->next;
            }
      }

      node* searchList(node* pHead, int data) {
            node* temp = pHead;
            if (temp == NULL)
                  return NULL;

            while (temp->data != data && temp->next != NULL)
                  temp = temp->next;

            if (temp->data == data)
                  return temp;
            return NULL;
      }


      void nodeTest() {
            node* head = new node(13);
            insertEnd(head, new node(5));
            insertEnd(head, new node(2));
            insertEnd(head, new node(3));
            insertEnd(head, new node(32));
            insertEnd(head, new node(24));
            insertEnd(head, new node(7));
            std::cout << myMaxFunc(head, 0) << std::endl;

            node* head2 = new node(3);
            insertEnd(head2, new node(6));
            insertEnd(head2, new node(13));
            insertEnd(head2, new node(5));
            insertEnd(head2, new node(17));
            fun1(head2);
            std::cout << std::endl;

            insertHead(head2, 9);
            fun1(head2);
            std::cout << std::endl;

            insertEnd(head2, 10);
            fun1(head2);
            std::cout << std::endl;

            insertMiddle(searchList(head2, 13), 15);
            fun1(head2);
            std::cout << std::endl;

            deleteValue(head2, 3);
            fun1(head2);
            std::cout << std::endl;

            deleteValue(head2, 17);
            fun1(head2);
            std::cout << std::endl;

            deleteNode(head2, searchList(head2, 13));
            fun1(head2);
            std::cout << std::endl;

            fun2(head2);
            std::cout << std::endl;

            print(head2);
            std::cout << std::endl;

            func1(head2);
            // looped
            // print(head2);
            printCircle(head2);
            std::cout << std::endl;
      }

      void tutTest() {
            std::cout << "Prime test\n";
            int arr[] = {1, 2, 3, 4, 5, 6};
            onePrime(arr, 6);
            std::cout << std::endl;
            allPrime(arr, 6);
            std::cout << std::endl;

            std::cout << "Node test\n";
            nodeTest();

            std::cout << "Fibo test\n";
            std::cout << Fibonacci(10) << std::endl;
            std::cout << Fibonacci(20) << std::endl;
            std::cout << Fibonacci(30) << std::endl;
            std::cout << Fibonacci(40) << std::endl;
      }

}    // namespace tut
}    // namespace week2