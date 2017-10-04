#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

namespace data
{
template <class data_type>
class BinaryTree {
      struct Node
      {
            data_type data;
            Node*     left;
            Node*     right;

            Node(data_type d = data_type(), Node* l = NULL, Node* r = NULL)
                : data(d), left(l), right(r) {}
      };

      typedef int size_t;
      enum class DIRECTION : int
      {
            LEFT  = 1,
            RIGHT = 2,
      };

      Node*  _root;
      size_t _size;

    public:
      BinaryTree() : _root(NULL), _size(0) {}

      BinaryTree(const BinaryTree& b) {}
      BinaryTree& operator=(const BinaryTree& b) {
            clear();
            return *this;
      }

      ~BinaryTree() {
            clear();
            _root = NULL;
            _size = 0;
      }


      // Use the tree

      void clear() {
            while (!isEmpty()) {
                  remove(_root);
            }
            _root = NULL;
      }

      inline bool isEmpty() const {
            return size() == 0;
      }

      inline size_t size() const {
            return _size;
      }


      void print(Node* n) const {
            if (n == NULL)
                  return;

            print(n->left);
            std::cout << n->data << " ";
            print(n->right);
      }

      void print() const {
            print(_root);
      }


      friend std::ostream& operator<<(std::ostream& o, const BinaryTree& b) {
            b.print();
            return o;
      }

      bool hasNoChild(Node* n) {
            return !hasOneChild(n);
      }
      bool hasOneChild(Node* n) {
            if (n->left)
                  return true;
            if (n->right)
                  return true;
            return false;
      }
      bool hasTwoChild(Node* n) {
            if (n->left && n->right)
                  return true;
            return false;
      }

      // insert
    protected:
      void insert(data_type d, Node*& root) {
            if (root == NULL)
                  root = new Node(d);
            else if (d < root->data)
                  insert(d, root->left);
            else
                  insert(d, root->right);
      }

    public:
      void insert(data_type d) {
            insert(d, _root);
            ++_size;
      }

      void remove(Node* preNode, DIRECTION dir) {}
};
}

#endif