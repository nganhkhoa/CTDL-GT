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

      // week1::lab::labTest();
      // week1::tut::tutTest();
      // week2::lab::labTest();
      // week2::tut::tutTest();
      // week2::onclass::onclassTest();
      week3::lab::labTest();
      week3::tut::tutTest();
      return 0;
#else    // UNITTEST
      testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
#endif
}