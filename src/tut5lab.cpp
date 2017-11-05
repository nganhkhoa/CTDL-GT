#include <tut5lab.h>
#include <string>
#include <iostream>
#include <Queue_LinkedList.h>
#include <Stack_LinkedList.h>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

namespace week5
{
TreeNode::TreeNode(string c) {
      character = c;
      count     = 1;
      left      = NULL;
      right     = NULL;
}

TreeNode::TreeNode(char c) {
      character = c;
      count     = 1;
      left      = NULL;
      right     = NULL;
}

TreeNode::~TreeNode() {
      left  = NULL;
      right = NULL;
}

void TreeNode::increaseCount() {
      count++;
}

int TreeNode::getCount() {
      return count;
}
void TreeNode::setCount(int i) {
      count = i;
}

string TreeNode::getChar() {
      return character;
}
void TreeNode::setChar(string s) {
      character = s;
}

TreeNode* TreeNode::getLeft() {
      return left;
}
void TreeNode::setLeft(TreeNode* l) {
      left = l;
}

TreeNode* TreeNode::getRight() {
      return right;
}
void TreeNode::setRight(TreeNode* r) {
      right = r;
}

void TreeNode::print() {
      cout << character << " ";
      if (left)
            left->print();
      if (right)
            right->print();
}

TreeNode* TreeNode::min() {

      if (!left && !right) {
            return this;
      }

      TreeNode* min = NULL;
      if (left)
            min = left->min();
      else if (right)
            min = right->min();

      return min;
}

TreeNode* TreeNode::remove(string s) {
      if (s < character) {
            if (left)
                  left = left->remove(s);
      }

      else if (s > character) {
            if (right)
                  right = right->remove(s);
      }

      else {
            if (!left && !right) {
                  delete this;
                  return NULL;
            }

            else if (left && right) {
                  TreeNode* min = right->min();
                  character     = min->getChar();
                  count         = min->getCount();

                  right = right->remove(character);
            }

            else {
                  TreeNode* temp = NULL;

                  if (left)
                        temp = left;
                  else
                        temp = right;

                  delete this;
                  return temp;
            }
      }

      return this;
}


BinarySearchTree::~BinarySearchTree() {
      if (root)
            delete root;
}

void BinarySearchTree::insert(TreeNode* tn) {

      if (root == NULL) {
            root = tn;
            return;
      }

      TreeNode* temp = root;
      while (true) {
            if (tn->getChar() < temp->getChar())
                  if (temp->getLeft())
                        temp = temp->getLeft();
                  else {
                        temp->setLeft(tn);
                        break;
                  }

            else if (tn->getChar() > temp->getChar()) {
                  if (temp->getRight())
                        temp = temp->getRight();
                  else {
                        temp->setRight(tn);
                        break;
                  }
            }

            else {
                  temp->increaseCount();
                  break;
            }
      }
}

void BinarySearchTree::remove(string s) {
      if (!isEmpty()) {
            root = root->remove(s);
      }
}

int BinarySearchTree::search(string s) {
      if (root == NULL)
            return 0;

      TreeNode* temp = root;
      while (true) {
            if (s < temp->getChar())
                  if (temp->getLeft())
                        temp = temp->getLeft();
                  else
                        return 0;

            else if (s > temp->getChar())
                  if (temp->getRight())
                        temp = temp->getRight();
                  else
                        return 0;

            else
                  return temp->getCount();
      }
}

void BinarySearchTree::print() {
      if (root)
            root->print();
}

BinarySearchTree* buildTreeFromString(string s) {
      BinarySearchTree* tree = new BinarySearchTree();
      for (char c : s) {
            TreeNode* tn = new TreeNode(c);
            tree->insert(tn);
      }
      return tree;
}

bool IntNode::BSTcheck() {
      if (left && right) {
            if (data >= left->data)
                  return false;
            if (data < right->data)
                  return false;
            return left->BSTcheck() && right->BSTcheck();
      }

      if (left) {
            if (data >= left->data)
                  return false;
            else
                  return left->BSTcheck();
      }

      if (right) {
            if (data < right->data)
                  return false;
            else
                  return right->BSTcheck();
      }

      return true;
}

int IntNode::Height() {
      if (!left && !right)
            return 0;

      int leftHeight = 0;
      if (left)
            leftHeight = left->Height() + 1;

      int rightHeight = 0;
      if (right)
            rightHeight = right->Height() + 1;

      return leftHeight > rightHeight ? leftHeight : rightHeight;
}

void labTest() {
      string sample = "A binary search tree is a binary tree with the "
                      "following properties: All items in the left "
                      "subtree are less than the root. All items in the "
                      "right subtree are greater than or equal to the "
                      "root. Each subtree is itself a binarysearch tree.";

      BinarySearchTree* sample_tree = buildTreeFromString(sample);
      sample_tree->print();

      cout << endl;

      cout << "b = " << to_string(sample_tree->search("b")) << endl;
      cout << "s = " << to_string(sample_tree->search("s")) << endl;
      cout << "t = " << to_string(sample_tree->search("t")) << endl;
}


TreeNode* loopInsert(TreeNode* root, TreeNode* newNode) {
      if (root == NULL)
            return newNode;

      TreeNode* temp = root;
      while (true) {
            if (newNode->getChar() < temp->getChar()) {
                  if (temp->getLeft() == NULL) {
                        temp->setLeft(newNode);
                        break;
                  }
                  else
                        temp = temp->getLeft();
            }
            else if (newNode->getChar() > temp->getChar()) {
                  if (temp->getRight() == NULL) {
                        temp->setRight(newNode);
                        break;
                  }
                  else
                        temp = temp->getRight();
            }
            else {
                  temp->increaseCount();
                  break;
            }
      }
      return root;
}

void printPath(TreeNode* subroot, string searchedData) {
      TreeNode* temp = subroot;

      cout << "ROOT";
      while (temp->getChar() != searchedData && temp != NULL) {
            cout << " --> " << temp->getChar();
            if (searchedData < temp->getChar()) {
                  temp = temp->getLeft();
            }
            else if (searchedData > temp->getChar()) {
                  temp = temp->getRight();
            }
      }
      if (temp == NULL)
            cout << "NOT FOUND\n";
      else
            cout << temp->getChar() << " FOUND\n";
}

void printLeavesBFT(TreeNode* root) {
      if (root == NULL)
            return;

      data::Queue_LinkedList<TreeNode*>* queue =
         new data::Queue_LinkedList<TreeNode*>();
      queue->enqueue(root);

      while (!queue->isEmpty()) {
            TreeNode* temp = queue->front();
            if (temp->getLeft() == NULL && temp->getRight() == NULL)
                  cout << "Leaf: " << temp->getChar() << "\n";
            queue->enqueue(temp->getLeft());
            queue->enqueue(temp->getRight());
            queue->dequeue();
      }

      cout << "END\n";
}

void printLeavesLNR(TreeNode* subroot) {
      if (subroot == NULL)
            return;

      printLeavesLNR(subroot->getLeft());
      if (subroot->getLeft() == NULL && subroot->getRight() == NULL)
            cout << subroot->getChar();
      printLeavesLNR(subroot->getRight());
}

void printLeavesNLR(TreeNode* subroot) {
      if (subroot == NULL)
            return;

      if (subroot->getLeft() == NULL && subroot->getRight() == NULL)
            cout << subroot->getChar();

      printLeavesNLR(subroot->getLeft());
      printLeavesNLR(subroot->getRight());
}

void loopTraverseNLR(int* bst, int size) {
      if (size <= 0) {
            cout << endl;
            return;
      }

      if (*bst >= 0)
            cout << *bst << " ";

      loopTraverseNLR(bst + 1, size - 1);

      loopTraverseNLR(bst + 2, size - 2);
}
void loopTraverseLNR(int* bst, int size) {}
void loopTraverseBFS(int* bst, int size) {}


void tutTest() {
      int size      = 7;
      int bst[size] = {17, 10, 21, -1, -1, 19, 25};
      loopTraverseNLR(bst, size);
}


namespace onclass
{}    // namespace onclass
}    // namespace week5