#ifndef TUT1LAB_H
#define TUT1LAB_H

#include <iostream>
#include <string>
namespace week1
{
namespace lab
{
      void        upper(char*, int);
      std::string fibo(int n);
      std::string fibo_recur(int n);
      int  bin2dec(int);
      void MatrixTest();
      void FastFoodTest();
      void labTest();

      class FastFood {
          private:
            std::string _name;
            std::string _id;
            float       _cost;
            float       _deliciousness;

          public:
            FastFood(
               const std::string& n,
               const std::string& i,
               const float&       c,
               const float&       d)
                : _name(n), _id(i), _cost(c), _deliciousness(d) {}

            FastFood() : _name(""), _id(""), _cost(0), _deliciousness(0) {}

            ~FastFood() {}

            std::string name() const {
                  return _name;
            }

            friend std::ostream&
               operator<<(std::ostream& out, const FastFood& f) {
                  out << f.name();
                  return out;
            }

            bool isCheap() {
                  return _cost <= 5;
            }

            bool isDelicious() {
                  return _deliciousness >= 8;
            }

            float deliciousness() {
                  return _deliciousness;
            }

            friend void
               goodFood(const std::initializer_list<FastFood>& ListFastFood) {
                  for (FastFood f : ListFastFood) {
                        if (f.isCheap() && f.isDelicious()) {
                              std::cout << f << std::endl;
                        }
                  }
                  std::cout << "End list" << std::endl;
            }

            friend void goodFood(FastFood* ListFastFood, int items) {
                  std::cout << "Good Food, cheap and delicious" << std::endl;
                  for (int i = 0; i < items; i++) {
                        FastFood f = ListFastFood[i];
                        if (f.isCheap() && f.isDelicious()) {
                              std::cout << f << std::endl;
                        }
                  }
                  std::cout << "End list" << std::endl;
            }

            friend FastFood* deliciousFood(FastFood* ListFastFood, int items) {
                  if (items == 0)
                        return NULL;
                  if (items == 1) {
                        std::cout << "1 food returned" << std::endl;
                        return new FastFood[2]{ListFastFood[0], FastFood()};
                  }

                  // two boxes for 2 maximum
                  struct
                  {
                        int   place     = -1;
                        float delicious = -1;
                  } out1, out2;

                  for (int i = 0; i < items; i++) {
                        float delicious = ListFastFood[i].deliciousness();
                        if (delicious <= out2.delicious)
                              continue;

                        if (delicious > out1.delicious) {
                              // box2 = box1
                              // box1 = new
                              out2.place     = out1.place;
                              out2.delicious = out1.delicious;
                              out1.place     = i;
                              out1.delicious = delicious;
                              continue;
                        }
                        else if (delicious == out1.delicious) {
                              if (out2.delicious == delicious)
                                    continue;
                        }

                        if (delicious > out2.delicious) {
                              out2.place     = i;
                              out2.delicious = delicious;
                        }

                        if ((out1.delicious == 10) && (out2.delicious == 10))
                              break;
                  }

                  std::cout << "2 food returned" << std::endl;
                  FastFood* result = new FastFood[2]{ListFastFood[out1.place],
                                                     ListFastFood[out2.place]};
                  return result;
            }
      };


      void      goodFood(FastFood*, int);
      FastFood* deliciousFood(FastFood*, int);
}    // namespace lab


namespace tut
{
      class Test {
            int _x;

          public:
            Test() {
                  _x = 5;
            }
            int x() const {
                  return _x;
            }
      };

      void problem1();
      void problem2();
      void problem3();
      int  problem4(int);
      bool problem5();

      void f(int* x);
      void g(int*& x);
      void h(const int*& x);
      void problem6();

      void problem7();
      void problem8();
      int  problem9(int, int*);

      void tutTest();
}    // namespace tut
}
#endif