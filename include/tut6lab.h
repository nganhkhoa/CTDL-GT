#ifndef TUT6LAB_H
#define TUT6LAB_H

#include <iostream>

namespace week6
{
namespace lab
{
      template <class data_type>
      class AVL {
            struct node
            {

                  enum class BF : int
                  {
                        left = -1,
                        equal,
                        right
                  };

                  data_type data;
                  node*     left;
                  node*     right;

                  int height;
                  BF  balance;

                  node(data_type d) : data(d) {
                        left = right = nullptr;
                        height       = 1;
                        balance      = BF::equal;
                  }

                  ~node() {
                        left = right = nullptr;
                  }

                  void setHeight() {
                        if (left && right)
                              height = left->height > right->height
                                          ? left->height + 1
                                          : right->height + 1;
                        else if (left)
                              height = left->height + 1;
                        else if (right)
                              height = right->height + 1;
                  }

                  void setBalance() {
                        if (left && right)
                              balance = BF(right->height - left->height);
                        else if (left)
                              balance = BF::left;
                        else if (right)
                              balance = BF::right;
                  }

                  void balanceNode() {
                        switch (balance) {
                              // parent left
                              case BF::left:
                                    switch (left->balance) {
                                          case BF::left:
                                          case BF::right:
                                          case BF::equal:
                                                return;
                                    }
                                    return;

                              // parent right
                              case BF::right:
                                    switch (right->balance) {
                                          case BF::left:
                                          case BF::right:
                                          case BF::equal:
                                                return;
                                    }
                                    return;

                              case BF::equal:
                                    return;

                              default:
                                    return;
                        }
                  }

                  void resetNode() {
                        setHeight();
                        setBalance();

                        if (balance != BF::equal)
                              balanceNode();
                  }
            };

            node* root;
            int   _size;

            void insert(node*& n, data_type d) {
                  if (n == NULL) {
                        n = new node(d);
                        return;
                  }

                  if (d < n->data) {
                        insert(n->left, d);
                  }
                  else {
                        insert(n->right, d);
                  }

                  n->resetNode();
            }

          public:
            void insert(data_type d) {
                  if (root == nullptr) {
                        root = new node(d);
                  }
                  else {
                        if (d < root->data)
                              insert(root->left, d);
                        else
                              insert(root->right, d);

                        root->resetNode();
                  }
                  return;
            }
      };


      void labTest();
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week6


#endif
