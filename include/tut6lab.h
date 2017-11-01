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
                        farLeft = -2,
                        left,
                        equal,
                        right,
                        farRight
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
                        else
                              height = 1;
                  }

                  void setBalance() {
                        if (left && right)
                              balance = BF(right->height - left->height);
                        else if (left)
                              balance = BF(-left->height);
                        else if (right)
                              balance = BF(right->height);
                        else
                              balance = BF::equal;
                  }

                  node* rotateLeft() {
                        node* newRoot = this->right;

                        this->right   = newRoot->left;
                        newRoot->left = this;

                        this->resetNode();
                        newRoot->resetNode();

                        return newRoot;
                  }

                  node* rotateRight() {
                        node* newRoot = this->left;

                        this->left     = newRoot->right;
                        newRoot->right = this;

                        this->resetNode();
                        newRoot->resetNode();

                        return newRoot;
                  }

                  node* balanceNode() {
                        switch (balance) {
                              // parent left
                              case BF::farLeft:
                                    switch (left->balance) {
                                          case BF::left:
                                                return rotateRight();
                                          case BF::right:
                                                left = left->rotateLeft();
                                                return rotateRight();
                                          default:
                                                return this;
                                    }

                              // parent right
                              case BF::farRight:
                                    switch (right->balance) {
                                          case BF::left:
                                                right = right->rotateRight();
                                                return rotateLeft();
                                          case BF::right:
                                                return rotateLeft();
                                          default:
                                                return this;
                                    }

                              default:
                                    return this;
                        }
                  }

                  void resetNode() {
                        setHeight();
                        setBalance();
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
                  n = n->balanceNode();
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
                        root = root->balanceNode();
                  }
                  _size++;
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
