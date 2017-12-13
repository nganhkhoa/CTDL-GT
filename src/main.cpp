#include <prebuild.h>
#ifndef NDEBUG
#include <debug.h>
#endif
#include "version.h"
#ifdef UNITTEST
#include <gtest/gtest.h>
#endif
#include <ctime>

// to be include here

#include <tut1lab.h>
#include <tut2lab.h>
#include <tut3lab.h>
#include <tut4lab.h>
#include <tut5lab.h>
#include <tut6lab.h>

#include <test1.h>
#include <test2.h>

#include <fun.h>

using namespace std;

int main(int argc, char** argv) {

#ifndef UNITTEST
      if (argc == 2) {
            if (strcmp(argv[1], "--version") == 0) {
                  cout << "VERSION: ";
                  cout << VERSION_MAJOR << ".";
                  cout << VERSION_MINOR << ".";
                  cout << VERSION_FIX << endl;
                  cout << "Created by luibo" << endl;
                  return 1;
            }
      }
      srand(time(NULL));
      clearscreen();

#ifndef NDEBUG
      console->info("Logging system initialized");
#endif    // DEBUG

      int choice = 0;

      while (true) {
            clearscreen();

            cout << "Chose which to run:\n";
            cout << "1.  Week 1\n";
            cout << "2.  Week 2\n";
            cout << "3.  Week 3\n";
            cout << "4.  Week 4\n";
            cout << "5.  Week 5\n";
            cout << "6.  Week 6\n";
            cout << "7.  Week 7\n";
            cout << "8.  Week 8\n";
            cout << "9.  Test 1\n";
            cout << "10. Test 2\n";
            cout << "11. Data structure Test\n";
            cout << "12. Exit\n";

            cout << "\n\t>> ";
            cin >> choice;
            cin.ignore();

            console->info("Input {}", choice);

            switch (choice) {
                  case 1:
                        week1::lab::labTest();
                        week1::tut::tutTest();
                        break;
                  case 2:
                        week2::lab::labTest();
                        week2::tut::tutTest();
                        week2::onclass::onclassTest();
                        break;
                  case 3:
                        week3::lab::labTest();
                        week3::tut::tutTest();
                        break;
                  case 4:
                        week4::lab::labTest();
                        week4::tut::tutTest();
                        break;
                  case 5:
                        week5::labTest();
                        week5::tutTest();
                        break;
                  case 6:
                        week6::lab::labTest();
                        // week6::tut::tutTest();
                        break;
                  case 7:
                        break;
                  case 8:
                        break;
                  case 9:
                        test1::L01::Test();
                        test1::L02::Test();
                        break;
                  case 10:
                        test2::L01::Test();
                        test2::L02::Test();
                        break;
                  case 11:

                        cout << "Chose which data structure:\n";
                        cout << "1.  Linked List\n";
                        cout << "2.  Stack\n";
                        cout << "3.  Queue\n";
                        cout << "4.  Binary Seach Tree\n";
                        cout << "5.  AVL Tree (comming soon)\n";
                        cout << "6.  BTree (not complete)\n";
                        cout << "7.  Heap\n";
                        cout << "8.  Hash\n";
                        cout << "9.  Graph (not complete)\n";
                        cout << "10. Exit\n";
                        cout << "\n\t>> ";

                        cin >> choice;
                        cin.ignore();
                        console->info("Choice made {}", choice);

                        switch (choice) {
                              case 1:
                                    fun::SinglyLinkedListTest();
                                    break;
                              case 2:
                                    fun::Stack_LinkedListTest();
                                    break;
                              case 3:
                                    fun::Queue_LinkedListTest();
                                    break;
                              case 4:
                                    fun::BinaryTreeTest();
                                    break;
                              case 5:
                                    // fun::AVLTest();
                                    break;
                              case 6:
                                    fun::BTreeTest();
                                    break;
                              case 7:
                                    fun::HeapTest();
                                    break;
                              case 8:
                                    fun::HashTest();
                                    break;
                              case 9:
                                    fun::GraphTest();
                                    break;
                              default:
                                    break;
                        }
                  case 12:
                        return 0;
                  default:
                        break;
            }
      }
      return 0;
#else    // UNITTEST
      testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
#endif
}