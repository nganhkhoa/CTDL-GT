#include <tut1lab.h>
#include <iostream>
#include <cmath>
#include <debug.h>


#include <matrix.h>
namespace week1
{
namespace lab
{
      void upper(char* arr, int n) {
            if (n <= 0)
                  return;
            if (arr == NULL)
                  return;
            for (int i = 0; i < n; i++) {
                  if (arr[i] >= 'a' && arr[i] <= 'z') {
                        arr[i] -= 'a' - 'A';
                  }
            }
            return;
      }

      std::string fibo(int n) {
            if (n == 0)
                  return "0";
            else if (n == 1)
                  return "01";
            std::string f1 = "0";
            std::string f2 = "01";
            for (int i = 1; i < n - 1; i++) {
                  std::string f = f1;
                  f1 += f2;
                  f2 = f;
            }
            return f1;
      }

      std::string fibo_recur(int n) {
            if (n == 0)
                  return "0";
            else if (n == 1)
                  return "01";
            else
                  return fibo_recur(n - 1) + fibo_recur(n - 2);
      }

      void MatrixTest() {
            data::Matrix<double>* a;
            data::Matrix<double>* b;
            data::Matrix<double>* c;

            // lazy lambda for cleanning
            auto clear = [&]() {
                  delete c;
                  c = NULL;
                  delete b;
                  b = NULL;
                  delete a;
                  a = NULL;
            };

            a =
               new data::Matrix<double>(new double[6]{1, 0, 2, -1, 3, 1}, 2, 3);
            b = new data::Matrix<double>(new double[6]{3, 1, 2, 1, 1, 0}, 3, 2);
            c = new data::Matrix<double>(*a * *b);
            std::cout << *c << std::endl;
            // 5 1
            // 4 2

            clear();

            a =
               new data::Matrix<double>(new double[6]{1, 4, 2, -1, 0, 4}, 2, 3);
            b = new data::Matrix<double>(
               new double[9]{2, 4, 1, 2, -3, 0, 3, 5, 1}, 3, 3);
            c = new data::Matrix<double>(*a * *b);
            std::cout << *c << std::endl;
            // 16 2 3
            // 10 16 3

            clear();
      }

      void FastFoodTest() {
            // random food with attributes
            FastFood* ListFastFood =
               new FastFood[12]{FastFood("qmCuKCWHalVcYoc", "16", 8, 6),
                                FastFood("hXPajLWnLRNrpv", "78", 7, 9),
                                FastFood("mVqiaIrYv", "27", 1, 10),
                                FastFood("tIJKYrsaloSkxtF", "42", 9, 2),
                                FastFood("ESmSWCdOBkYyrwQSReD", "57", 7, 1),
                                FastFood("nUZNthii", "93", 6, 4),
                                FastFood("OlqYVMIHsateCh", "73", 4, 10),
                                FastFood("HMUGpbtmVQsGZRZPS", "21", 1, 2),
                                FastFood("jBJfj", "35", 6, 4),
                                FastFood("nbaafQAngTsOPjyQMvk", "64", 9, 5),
                                FastFood("XowyGNJhRXK", "4", 2, 10),
                                FastFood("hPuIYJHzoXhoaRaVEd", "79", 9, 9)};

            goodFood(ListFastFood, 12);

            std::cout << "Most 2 delicious food" << std::endl;
            FastFood* toEat = deliciousFood(ListFastFood, 12);
            if (toEat != NULL)
                  for (int i = 0; i < 2; i++)
                        std::cout << toEat[i] << std::endl;
      }


      int bin2dec(int num) {
            static int mu = 0;
            if (num == 0) {
                  mu = 0;
                  return 0;
            }
            return (num % 10) * pow(2, mu++) + bin2dec((num - (num % 10)) / 10);
      }

      void labTest() {
            char arr[] = {'a', 'B', 'c', '3', '\0'};
            std::cout << arr << std::endl;
            upper(arr, 5);
            std::cout << arr << std::endl;

            MatrixTest();

            std::cout << fibo(5) << std::endl;
            std::cout << fibo_recur(5) << std::endl;

            FastFoodTest();

            std::cout << bin2dec(1101) << std::endl;
      }
}    // namespace lab

namespace tut
{
      void problem1() {
            char str[12] = "123\0";
            std::cout << (int) str[5] << str[6];
            // 0 + khoảng trắng
      }

      void problem2() {
            int  a = 2, b = 3, c = 4;
            int* arr[3] = {&a, &b, &c};
            std::cout << *arr[arr[2][0] - *arr[1]];
            // 3
      }

      void problem3() {
            int* ptr = new int[20];
            delete[] ptr;
            // delete ptr;
            ptr = NULL;
            delete ptr;
            // ok
      }

      int problem4(int n) {
            if (n <= 2)
                  return n;
            int tmp = n;
            for (int i = 2; i * i <= n; i++) {
                  if (n % i == 0) {
                        tmp = 0;
                        break;
                  }
            }
            return tmp + problem4(n - 1);
      }

      bool problem5() {
            int x;
            std::cin >> x;
            x /= 3;
            for (; x != 0; x /= 3) {
                  if (x % 3 == 0)
                        return true;
            }
            return false;
      }

      void f(int* x) {
            // copy pointer
            int a = 4;
            x     = &a;
      }

      void g(int*& x) {
            int a = 3;
            x     = &a;
      }

      void h(const int*& x) {
            int b = 2;
            x     = &b;
      }

      void problem6() {
            int* p = new int;
            *p     = 5;
            f(p);
            std::cout << p << " " << *p << std::endl;
            g(p);
            std::cout << p << " " << *p << std::endl;
            std::cout << p << " " << *p << std::endl;
            const int* p1 = p;
            h(p1);
            std::cout << p << " " << *p << std::endl;
            std::cout << p << " " << *p << std::endl;
      }

      void problem7() {
            Test* t = new Test();
            std::cout << t->x();
      }

      void problem8() {
            int** p = new int*[5];
            int*  q = new int[5];
            for (int i = 0; i < 5; i++) {
                  q[i] = i;
            }

            p[3] = q;
            delete p;
            delete q;
            delete[] q;
      }

      int problem9(int n, int* f_p) {
            int t, f;
            if (n <= 1) {
                  *f_p = *f_p / 2;
                  return *f_p;
            }
            t    = problem9(n - 1, f_p);
            f    = t + *f_p;
            *f_p = t;
            return f;
      }

      void tutTest() {
            console->info("Problem 1");
            problem1();
            console->info("Problem 2");
            problem2();
            console->info("Problem 3");
            problem3();
            console->info("Problem 4");
            std::cout << problem4(24) << std::endl;
            console->info("Problem 5");
            std::cout << problem5() << std::endl;
            console->info("Problem 6");
            problem6();
            console->info("Problem 7");
            problem7();
            console->info("Problem 8");
            // problem8();
            console->info("Problem 9");
            int x = 15;
            std::cout << problem9(5, &x) << std::endl;
      }
}    // namespace tut
}    // namespace week1