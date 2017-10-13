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
                  // remove(_root->data);
            }
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
      int minData(Node* n) {
            if (n->left)
                  return minData(n->left);
            else if (n->right)
                  return minData(n->right);
            else {
                  return n->data;
            }
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

            /**
             * A no recursive way
             * Node* temp = _root;
             * while (temp != NULL) {
             *    if (d < temp->data)
             *          temp = temp->left;
             *    else
             *          temp = temp->right;
             * }
             * temp = new Node(d);
             * ++_size;
             */
      }

      void remove(data_type d, Node*& deleteNode) {
            if (deleteNode == NULL)
                  return;

            if (d < deleteNode->data)
                  remove(d, deleteNode->left);
            else if (d > deleteNode->data)
                  remove(d, deleteNode->right);
            else {
                  // deleteNode is the node to be deleted
                  if (hasNoChild(deleteNode)) {
                        delete deleteNode;
                        deleteNode = NULL;
                  }

                  else if (hasTwoChild(deleteNode)) {
                        data_type min    = minData(deleteNode->right);
                        deleteNode->data = min;
                        remove(min, deleteNode->right);
                  }

                  else {
                        // one child
                        Node* temp = deleteNode;

                        if (deleteNode->left)
                              deleteNode = deleteNode->left;
                        else
                              deleteNode = deleteNode->right;

                        delete temp;
                        temp = NULL;
                  }
            }
      }

    public:
      void insert(data_type d) {
            insert(d, _root);
            ++_size;
      }

      void remove(data_type d) {
            if (isEmpty())
                  return;
            // delete root
            if (_root->data == d) {
            }

            // delete child of root
            else {
                  remove(d, _root);
            }

            --_size;
      }
};
}

#endif