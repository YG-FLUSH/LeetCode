#ifndef BTREE_H
#define BTREE_H
#include<iostream>
const int _INIT = -1;
const int _LEFT = 1;
const int _RIGHT = 0;


struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BTree{
    public:
        BTree(int *arr, int len);

        ~BTree();

        TreeNode* find(int val);

        bool insert(int val);
        bool insert(TreeNode *node);

    private:
        TreeNode *head;

    protected:
        TreeNode *innerFind(TreeNode*, TreeNode*, int*);
        void free(TreeNode*);

};

ostream& operator << (ostream &out, BTree * bt);

#endif
