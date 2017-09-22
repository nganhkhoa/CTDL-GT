#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

namespace data
{
template <class data_type>
class BinaryTree {
      typedef int size_t;

    protected:
      struct node
      {
            data_type data;
            node*     left;
            node*     right;

            node(data_type d = data_type(), node* l = NULL, node* r = NULL)
                : data(d), left(l), right(r) {}
      };

      node*  _root;
      size_t _size;

    public:
      size_t size() const {
            return _size;
      }

      bool isEmpty() const {
            return size() == 0;
      }


    public:
      BinaryTree() : _root(NULL), _size(0) {}
      BinaryTree(const BinaryTree& bt) {}
      BinaryTree& operator=(const BinaryTree& bt) {}
      ~BinaryTree() {
            clear();
            delete _root;
            _root = NULL;
      }


      void clear() {}
};
}

#endif