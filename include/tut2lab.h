#ifndef TUT2LAB_H
#define TUT2LAB_H

#include <iostream>
#include <ctime>
#include <cmath>

#include <LinkedList.h>
#include <Coordinate.h>
#include <Matrix.h>


namespace week2
{
namespace lab
{
      class SecretGarden : public data::Matrix<int> {

            data::LinkedList<data::LinkedList<data::Coordinate>>* answer = NULL;
            int                                                   ways   = 0;
            void                                                  solve() {
                  // check surround 0 and 2 for -1
                  const data::Coordinate zero(0, 0);
                  const data::Coordinate two(_col - 1, _row - 1);

                  if (
                     (*this)[zero + data::i_vector] == -1 &&
                     (*this)[zero - data::j_vector] == -1)
                        return;
                  if (
                     (*this)[two - data::i_vector] == -1 &&
                     (*this)[two + data::j_vector] == -1)
                        return;

                  // std::cout << *this << std::endl;
                  findWay(zero);
            }

            // recursive find way
            void findWay(const data::Coordinate& c) {
                  // ans after first run will left back data
                  // haven't found a way to delete those
                  static data::LinkedList<data::Coordinate>* ans = NULL;

                  if ((*this)[c] == 2) {
                        addAnswer(*ans);    // reached destination add in answer
                        ans->removeEnd();    // backtracking
                        return;
                  }
                  else if ((*this)[c] == 0) {
                        /**
                        // change to below
                        if (ans != NULL) {
                              delete ans;
                              ans = NULL;
                        }
                        */
                        ans = new data::LinkedList<data::Coordinate>(c);
                  }

                  const data::Coordinate rightTile = c + data::i_vector;
                  const data::Coordinate downTile  = c - data::j_vector;

                  const int rightData = (*this)[rightTile];
                  const int downData  = (*this)[downTile];

                  if (rightTile.x() >= _col) {    // out right, check below
                        if (downData == 1 || downData == 2) {
                              ans->insertEnd(downTile);
                              findWay(downTile);
                        }
                        ans->removeEnd();    // backtracking
                        return;
                  }
                  if (rightData == 1 || rightData == 2) {
                        ans->insertEnd(rightTile);
                        findWay(rightTile);
                        // ans->removeEnd();    // backtracking
                  }


                  if (downTile.y() <= -_row) {    // out down, quit
                        ans->removeEnd();         // backtracking
                        return;
                  }
                  if (downData == 1 || downData == 2) {
                        ans->insertEnd(downTile);
                        findWay(downTile);
                  }
                  ans->removeEnd();    // backtracking
                  if ((*this)[c] == 0) {
                        // when backtrack to first tile, clear all
                        delete ans;
                        ans = NULL;
                        // free memory
                  }
            }

            void addAnswer(const data::LinkedList<data::Coordinate>& l) {
                  if (answer == NULL)
                        answer = new data::LinkedList<
                           data::LinkedList<data::Coordinate>>(l);
                  else
                        answer->insertEnd(l);
                  ways++;
            }

          public:
            SecretGarden(int size) : data::Matrix<int>(size, size) {
                  if (size <= 1) {
                        delete _value;
                        _value = NULL;
                        return;
                  }
                  _value[0]               = 0;
                  _value[size * size - 1] = 2;

                  int tiles[4] = {-1, 1, 1, 1};
                  for (int i      = 1; i < size * size - 1; i++)
                        _value[i] = tiles[rand() % 4];    // random 1 and -1

                  solve();
            }

            SecretGarden(int* value, int size)
                : data::Matrix<int>(value, size, size) {
                  if (_value[0] != 0)
                        throw "No starting point";
                  if (_value[size * size - 1] != 2)
                        throw "No ending point";
                  for (int i = 1; i < size * size - 1; i++)
                        if (_value[i] != 1 && _value[i] != -1)
                              throw "Invalid point";
                  solve();
            }

            ~SecretGarden() {
                  if (answer != NULL) {
                        delete answer;
                        answer = NULL;
                  }
            }

            bool guess(const data::LinkedList<data::Coordinate>& guess) {
                  return false;
            }

            void showAnswer() {
                  if (ways == 0) {
                        std::cout << "No answer found" << std::endl;
                        return;
                  }
                  for (int i = 0; i < ways; i++)
                        std::cout << (*answer)[i] << std::endl;
            }

            void shortestPath() {
                  if (ways == 0) {
                        std::cout << "No way found" << std::endl;
                        return;
                  }
                  struct
                  {
                        int shortest;
                        int index;
                  } shortestWay;
                  shortestWay.shortest = (*answer)[0].size();
                  shortestWay.index    = 0;
                  for (int i = 1; i < ways; i++) {
                        int newPath = (*answer)[i].size();
                        if (newPath < shortestWay.shortest) {
                              shortestWay.shortest = newPath;
                              shortestWay.index    = i;
                        }
                  }
                  std::cout << (*answer)[shortestWay.index] << std::endl;
            }
      };

      void LinkedListTest();
      void polynomialTest();
      int  factorial(int);
      int  sumDownBy2(int);
      void secretGardenTest();
      void labTest();
}    // namespace lab

namespace tut
{
      bool isPrime(int);

      template <int n>
      void          onePrime(int[n]);
      void          onePrime(int*, int);

      template <int n>
      void          allPrime(int[n]);
      void          allPrime(int*, int);
      int           Fibonacci(int);


      struct node
      {
            int   data;
            node* next = NULL;
            node(int d) : data(d) {}
      };

      /// I do it myself
      void insertHead(node*&, node*);
      void insertEnd(node*, node*);
      void insertMiddle(node*, node*);
      void deleteValue(node*&, int);
      void deleteNode(node*&, node*);
      void print(node*);

      // provided
      int   myMaxFunc(node*, int);
      void  fun1(node*);
      void  fun2(node*);
      void  func1(node*);
      node* searchList(node*, int);
      void  nodeTest();

      void tutTest();
}    // namespace tut
namespace onclass
{
      struct node
      {
            int   data;
            node* next = NULL;
            node(int d) : data(d) {}
      };

      void  insertEnd(node*, node*);
      void  insertEnd(node*, int);
      void  deleteNode(node*&, node*);
      node* searchList(node*, int);
      void  deleteNode2Times(node*&, int);
      void  print(node*);

      void onclassTest();
}
}

#endif