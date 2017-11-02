#ifndef AVL_H
#define AVL_H

#include <iostream>

#include <SinglyLinkedList.h>
#include <Queue_LinkedList.h>

namespace data
{
template <class data_type>
class AVL {
    protected:
      struct node
      {
            enum class BF : int
            {
                  // balance is calculated by
                  // subtraction of two height
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
                  height       = 0;
                  balance      = BF::equal;
            }

            ~node() {
                  left = right = nullptr;
            }

            bool oneChild() {
                  if (left && !right)
                        return true;
                  if (right && !left)
                        return true;
                  return false;
            }

            bool noChild() {
                  return !left && !right;
            }

            bool twoChild() {
                  return left && right;
            }

            data_type& min() {
                  if (left)
                        return left->min();
                  else
                        return retrive();
            }

            data_type& retrive() {
                  return data;
            }

            data_type& retrive() const {
                  return data;
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
                        height = 0;
            }

            void setBalance() {
                  if (left && right)
                        balance = BF(right->height - left->height);
                  else if (left)
                        // left is < 0
                        balance = BF(-left->height - 1);
                  else if (right)
                        balance = BF(right->height + 1);
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

      // data
      node*  root;
      size_t _size;

    private:
      // method
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

      bool remove(node*& n, const data_type& d) {
            if (n == nullptr)
                  return false;

            bool status = false;
            if (d < n->data)
                  status = remove(n->left, d);

            else if (d > n->data)
                  status = remove(n->right, d);

            else {
                  if (n->noChild()) {
                        delete n;
                        n = nullptr;
                  }

                  else if (n->twoChild()) {
                        data_type& d = n->right->min();
                        // the only copy, faster
                        n->data = d;
                        remove(n->right, d);
                  }

                  else {
                        // one child
                        node* temp = n;
                        n          = n->left ? n->left : n->right;
                        delete temp;
                        temp = nullptr;
                  }

                  status = true;
            }

            if (n) {
                  n->resetNode();
                  n = n->balanceNode();
            }
            return status;
      }

    public:
      // what user use

      AVL() {
            _size = 0;
            root  = nullptr;
      }

      ~AVL() {
            while (!isEmpty())
                  remove(root->data);
      }

      inline size_t size() const {
            return _size;
      }

      inline bool isEmpty() const {
            return size() == 0;
      }

      bool isFull() const {
            try {
                  node* temp = new node({});
                  delete temp;
                  temp = nullptr;
                  return false;
            } catch (std::bad_alloc& bal) {
                  return true;
            }
      }

      bool insert(data_type d) {
            if (isFull())
                  return false;

            insert(root, d);

            _size++;
            return true;
      }

      bool remove(const data_type& d) {
            if (isEmpty())
                  return false;

            if (!remove(root, d))
                  return false;

            _size--;
            return true;
      }

      void BFStraverse(void (*op)(data_type&)) {
            if (isEmpty())
                  return;

            Queue_LinkedList<node*> queue;
            queue.enqueue(root);

            while (!queue.isEmpty()) {
                  node* temp = queue.front();

                  if (temp->left)
                        queue.enqueue(temp->left);
                  if (temp->right)
                        queue.enqueue(temp->right);

                  op(temp->data);
                  queue.dequeue();
            }
      }
      void BFStraverse(void (*op)(data_type&, void*), void* v) {
            if (isEmpty())
                  return;

            Queue_LinkedList<node*> queue;
            queue.enqueue(root);

            while (!queue.isEmpty()) {
                  node* temp = queue.front();

                  if (temp->left)
                        queue.enqueue(temp->left);
                  if (temp->right)
                        queue.enqueue(temp->right);

                  op(temp->data, v);
                  queue.dequeue();
            }
      }

      // find data and return pointer to data in list
      SinglyLinkedList<data_type*>* search(const data_type& d) {
            SinglyLinkedList<data_type*>* ret =
               new SinglyLinkedList<data_type*>();

            if (isEmpty())
                  return ret;

            else {
                  struct Ans
                  {
                        SinglyLinkedList<data_type*>* result;
                        data_type                     data;

                        Ans(const data_type& d) {
                              data   = d;
                              result = new SinglyLinkedList<data_type*>();
                        }

                        ~Ans() {
                              result = NULL;
                        }
                  };

                  auto getList = [](data_type& d, void* v) {
                        Ans* ans = (Ans*) v;

                        if (ans->data == d)
                              ans->result->insertHead(&d);
                  };

                  Ans* ans = new Ans(d);
                  BFStraverse(getList, ans);
                  ret = ans->result;

                  delete ans;
                  ans = NULL;
            }

            return ret;
      }
};
}

#endif
