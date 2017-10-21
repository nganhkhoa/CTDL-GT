#ifndef TUT5LAB_H
#define TUT5LAB_H

#include <string>

namespace week5
{
namespace tut
{}    // namespace tut
namespace lab
{
      class TreeNode {
          private:
            std::string character;
            int         count;
            TreeNode*   left;
            TreeNode*   right;

          public:
            TreeNode(std::string);
            TreeNode(char);
            ~TreeNode();

            void increaseCount();

            int  getCount();
            void setCount(int);

            std::string getChar();
            void        setChar(std::string);

            TreeNode* getLeft();
            void      setLeft(TreeNode*);

            TreeNode* getRight();
            void      setRight(TreeNode*);

            void print();
      };

      class BinarySearchTree {
          private:
            TreeNode* root = NULL;

          public:
            ~BinarySearchTree();
            void insert(TreeNode*);
            void remove(std::string);
            int  search(std::string);
            void print();
      };

      class IntNode {
          private:
            int       data;
            int       count;
            IntNode* left;
            IntNode* right;

      };

      BinarySearchTree* buildTreeFromString(std::string);


      void labTest();

}    // namespace lab
namespace onclass
{}    // namespace onclass
}    // namespace week5

#endif