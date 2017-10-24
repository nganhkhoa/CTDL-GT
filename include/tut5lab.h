#ifndef TUT5LAB_H
#define TUT5LAB_H

#include <string>

namespace week5
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
      int      data;
      int      count;
      IntNode* left;
      IntNode* right;

    public:
      bool BSTcheck();
      int  Height();
};


TreeNode* loopInsert(TreeNode*, TreeNode*);
void      printPath(TreeNode*, std::string);
void      printLeavesBFT(TreeNode*);
void      printLeavesLNR(TreeNode*);
void      printLeavesNLR(TreeNode*);
void      loopTraverseNLR(int*, int);
void      loopTraverseLNR(int*, int);
void      loopTraverseBFS(int*, int);

BinarySearchTree* buildTreeFromString(std::string);


void labTest();
void tutTest();

namespace onclass
{}    // namespace onclass
}    // namespace week5

#endif