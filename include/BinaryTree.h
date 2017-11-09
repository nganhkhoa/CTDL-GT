#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

namespace data
{
template <class data_type>
class BinaryTree {
    protected:
      struct node
      {
            data_type data;
            node*     left;
            node*     right;

            node(data_type d = data_type(), node* l = NULL, node* r = NULL)
                : data(d), left(l), right(r) {}

            bool hasNoChild() {
                  return !hasOneChild();
            }
            bool hasOneChild() {
                  if (left)
                        return true;
                  if (right)
                        return true;
                  return false;
            }
            bool hasTwoChild() {
                  if (left && right)
                        return true;
                  return false;
            }

            int minData() {
                  if (left)
                        return left->minData();
                  else if (right)
                        return right->minData();
                  else {
                        return data;
                  }
            }
      };

      typedef int size_t;

      node*  _root;
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
                  remove(_root->data);
            }
      }

      inline bool isEmpty() const {
            return size() == 0;
      }

      inline size_t size() const {
            return _size;
      }


      void print(node* n) const {
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

    protected:
      bool find(const data_type& d, node* root) {
            if (root == NULL)
                  return false;
            else if (d == root->data)
                  return true;
            else if (d < root->data)
                  find(d, root->left);
            else
                  find(d, root->right);
      }

    public:
      bool find(const data_type& d) {
            return find(d, _root);
      }

    protected:
      void insert(data_type d, node*& root) {
            if (root == NULL)
                  root = new node(d);
            else if (d < root->data)
                  insert(d, root->left);
            else
                  insert(d, root->right);
      }

      bool remove(data_type d, node*& deleteNode) {
            if (deleteNode == NULL)
                  return false;

            if (d < deleteNode->data)
                  remove(d, deleteNode->left);
            else if (d > deleteNode->data)
                  remove(d, deleteNode->right);
            else {
                  // deleteNode is the node to be deleted
                  if (deleteNode->hasNoChild()) {
                        delete deleteNode;
                        deleteNode = NULL;
                  }

                  else if (deleteNode->hasTwoChild()) {
                        data_type min    = deleteNode->right->minData();
                        deleteNode->data = min;
                        remove(min, deleteNode->right);
                  }

                  else {
                        // one child
                        node* temp = deleteNode;

                        if (deleteNode->left)
                              deleteNode = deleteNode->left;
                        else
                              deleteNode = deleteNode->right;

                        delete temp;
                        temp = NULL;
                  }
            }
            return true;
      }

    public:
      void insert(data_type d) {
            insert(d, _root);
            ++_size;
      }

      void insert0R(data_type d) {
            if (isEmpty()) {
                  _root = new node();
                  return;
            }
            node* temp = _root;
            while (true) {
                  if (d < temp->data) {
                        if (!temp->left) {
                              temp->left = new node(d);
                              break;
                        }
                        temp = temp->left;
                  }
                  else {
                        if (!temp->right) {
                              temp->right = new node(d);
                              break;
                        }
                        temp = temp->right;
                  }
            }
            ++_size;
      }

      bool remove(data_type d) {
            if (isEmpty())
                  return false;

            if (remove(d, _root)) {
                  --_size;
                  return true;
            }
            return false;
      }

      void balanceTree() {
            data_type RootData = _root->data;
            if (remove(RootData))
                  insert(RootData);
      }
};
}

#endif