#ifndef TREE_H
#define TREE_H

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * MakeTree(int *a, int n);
void FreeTree(TreeNode *root);
ostream & operator << (ostream & out, TreeNode * root);

#endif
