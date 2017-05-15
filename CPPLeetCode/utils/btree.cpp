#include<iostream>
#include"btree.h"

ostream& operator << (ostream &out, BTree *bt){


}

BTree::BTree(int *arr, int len){
    if(arr == NULL || len < 1){
        this->head = NULL;
    }
    this->head = new TreeNode(arr[0]);
    for(int i=1; i < len; ++i){
        this->insert(arr[i]);
    }
}

BTree::~BTree(){
    this->free(this->head);
}

void BTree::free(TreeNode *node){
    if(node->left != NULL)
        this->free(node->left);
    if(node->right != NULL)
        this->free(node->right);
    delete node;
}

TreeNode* BTree::find(int val){
    TreeNode *parent = this->head;
    TreeNode *node = new TreeNode(val);
    int flag = _INIT;
    return this->innerFind(node, parent, &flag);
}

TreeNode* BTree::innerFind(TreeNode *node, TreeNode *parent, int *flag){
    // flag 0 --> for left site; 1 for right site;
    if(parent->val > node->val){
        *flag = _LEFT;
        if(parent->left != NULL){
            parent = parent->left;
            return this->innerFind(node, parent, flag);
        }
        else{
            return NULL;
        }
    }
    else if(parent->val < node->val){
        *flag = _RIGHT;
        if(parent->right != NULL){
            parent = parent->right;
            return this->innerFind(node, parent, flag);
        }
        else{
            return NULL;
        }
    }
    else{
        return parent;
    }
}

bool BTree::insert(int val){
    TreeNode *node = new TreeNode(val);
    return this->insert(node);
}

bool BTree::insert(TreeNode *node){
    int flag = _INIT;
    TreeNode *parent = this->head;
    TreeNode * tmp = this->innerFind(node, parent, &flag);
    if(tmp == NULL){
        if(flag == _RIGHT){
            parent->right = node;
            return true;
        }
        else if(flag == _LEFT){
            parent->left = node;
            return true;
        }
    }
    return false;
}


