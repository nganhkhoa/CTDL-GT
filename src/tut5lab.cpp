#include <tut5lab.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

namespace week5
{
namespace tut
{}    // namespace tut
namespace lab
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
            if (left)
                  delete left;
            if (right)
                  delete right;
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

      void BinarySearchTree::remove(string s) {}

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


}    // namespace lab
namespace onclass
{}    // namespace onclass
}    // namespace week5