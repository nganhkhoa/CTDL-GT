#ifndef TUT6LAB_H
#define TUT6LAB_H

#include <AVL.h>

namespace week6
{
namespace lab
{
      class SumPathTree : public data::AVL<int> {
            data::SinglyLinkedList<data::SinglyLinkedList<int>*>* path;
            int                                                   sum;

          public:
            SumPathTree() : data::AVL<int>() {
                  path = nullptr;
            }
            ~SumPathTree() {
                  if (path) {
                        delete path;
                        path = nullptr;
                  }
            }

            bool FindPath(node* n, int s) {
                  if (n == nullptr)
                        return false;

                  s += n->data;

                  if (s == sum) {
                        data::SinglyLinkedList<int>* onePath =
                           new data::SinglyLinkedList<int>();

                        onePath->insertHead(n->data);
                        path->insertHead(onePath);
                        return true;
                  }

                  bool status = FindPath(n->left, s) || FindPath(n->right, s);
                  if (status)
                        path->front()->insertHead(n->data);

                  return status;
            }

            bool FindPath(node* n) {
                  if (n == nullptr)
                        return false;

                  bool pathFromRoot      = FindPath(n, 0);
                  bool pathFromLeftRoot  = FindPath(n->left);
                  bool pathFromRightRoot = FindPath(n->right);

                  return pathFromRoot || pathFromLeftRoot || pathFromRightRoot;
            }

            bool FindPath(int s) {
                  sum = s;
                  return FindPath(root);
            }

            int SumPath(int s) {
                  // save one last search
                  if (s == sum)
                        return path->size();

                  if (path)
                        delete path;

                  path =
                     new data::SinglyLinkedList<data::SinglyLinkedList<int>*>();

                  if (FindPath(s))
                        return path->size();
                  return 0;
            }

            void PrintPath() {
                  for (auto eachPath : *path) {
                        for (int pathNode : *eachPath) {
                              std::cout << pathNode << " --> ";
                        }
                        std::cout << "END\n";
                  }
            }
      };

      void SumPathTest();
      void labTest();
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week6


#endif
