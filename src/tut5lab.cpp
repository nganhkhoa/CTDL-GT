#include <tut5lab.h>

#include <string>
#include <iostream>

using std::string;
using std::cout;

namespace week5
{
namespace tut
{}    // namespace tut
namespace lab
{
      TreeNode::TreeNode(string c) {
            character = c;
            count     = 0;
            left      = NULL;
            right     = NULL;
      }

      TreeNode::TreeNode(char c) {
            character = c;
            count     = 0;
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
                  if (tn->character < temp->character)
                        if (temp->left)
                              temp = temp->left;
                        else {
                              temp->left = tn;
                              break;
                        }

                  else {
                        if (temp->right)
                              temp = temp->right;
                        else {
                              temp->right = tn;
                              break;
                        }
                  }
            }
      }

      void BinarySearchTree::remove(string s) {}

      int BinarySearchTree::search(string s) {
            return 0;
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
}    // namespace lab
namespace onclass
{}    // namespace onclass
}    // namespace week5