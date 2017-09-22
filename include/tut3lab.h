#ifndef TUT3LAB_H
#define TUT3LAB_H

#include <LinkedList.h>
#include <cstring>

namespace week3
{
namespace lab
{
      struct Student
      {
            char* ID;
            char* name;
            float mathScore;
            float englishScore;

            Student(
               const char* i = NULL,
               const char* n = NULL,
               float       m = 0,
               float       e = 0)
                : mathScore(m), englishScore(e) {
                  if (i != NULL) {
                        ID = new char[strlen(i)];
                        strcpy(ID, i);
                  }
                  if (n != NULL) {
                        name = new char[strlen(n)];
                        strcpy(name, n);
                  }
            }
      };
      class StudentList : public data::LinkedList<Student> {
          public:
            template <size_t size>
            StudentList(Student (&arr)[size]) : LinkedList<Student>(arr) {}

            friend std::ostream&
               operator<<(std::ostream& o, const StudentList& l) {
                  for (auto& s : l) {
                        o << "Student:\n";
                        o << s.name << " - " << s.ID << std::endl;
                        o << "Math:     " << s.mathScore << std::endl;
                        o << "English:  " << s.englishScore << std::endl;
                        o << "--------------------\n";
                  }
                  return o;
            }
      };

      struct node
      {
            int   data;
            node* next;
            node(int d = 0, node* n = NULL) : data(d), next(n) {}
      };
      node* ReverseNode(node*, int&);
      void  Print(node*);

      void PolynomialTest();
      void StudentTest();
      void ReverseNodeTest();
      void labTest();
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace data

#endif