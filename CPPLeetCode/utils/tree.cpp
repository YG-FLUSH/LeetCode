#include<iostream>
#include<queue>
#include"tree.h"

using namespace std;

TreeNode * MakeTree(int *a, int n){
    if (n < 1){
        return NULL;
    }
    TreeNode * root = new TreeNode(a[0]);
    queue<TreeNode*> traversal_queue;
    traversal_queue.push(root);

    for(int i=1; i < n; ){
        TreeNode * temp = traversal_queue.front();
        traversal_queue.pop();

        temp->left = new TreeNode(a[i++]);
        traversal_queue.push(temp->left);

        if (i < n){
            temp->right = new TreeNode(a[i++]);
            traversal_queue.push(temp->right);
        }
    }
    return root;
}

void FreeTree(TreeNode *root){
    if(root == NULL){
        return;
    }
    TreeNode * left = root->left;
    TreeNode * right = root->right;
    FreeTree(left);
    FreeTree(right);
    delete root;
    return ;
}

ostream & operator << (ostream & out, TreeNode * root){
    // leveltraversal
    if(root == NULL){
        return out;
    }
    queue<TreeNode*> traversal_queue;
    traversal_queue.push(root);

    while(!traversal_queue.empty()){
        TreeNode *temp = traversal_queue.front();
        traversal_queue.pop();
        cout << temp->val << " " ;

        if(temp->left != NULL){
            traversal_queue.push(temp->left);
        }
        if(temp->right != NULL){
            traversal_queue.push(temp->right);
        }
    }
    return out;
}

