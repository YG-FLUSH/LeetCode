#include<iostream>
#include<vector>
#include"../utils/tree.h"
#include"../utils/util.h"
using namespace std;

ostream & operator << (ostream & out, vector<string> str_list){
    for(int i=0; i < str_list.size(); ++i){
        out << str_list[i] << " ";
    }
    return out;
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<TreeNode*> before_node;
        result = this->forwardTraversal(root, before_node, result);
        return result;
    }

    vector<string> & forwardTraversal(TreeNode *node, vector<TreeNode*> &before_node, vector<string> &result){

        if(node == NULL){
            return result;
        }
        if(node->left == NULL && node->right == NULL){
            // before_node --> result
            before_node.push_back(node);

            string str = IntToString(before_node[0]->val);
            for(int i=1; i < before_node.size(); ++i){
                str += "->";
                str += IntToString(before_node[i]->val);
            }
            result.push_back(str);
            before_node.pop_back();

            return result;
        }

        before_node.push_back(node);
        forwardTraversal(node->left, before_node, result);

        forwardTraversal(node->right, before_node, result);
        before_node.pop_back();
        return result;
    }
};

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode * root = MakeTree(a, sizeof(a)/sizeof(int));
    cout << root << endl;
    cout << Solution().binaryTreePaths(root) << endl;
    FreeTree(root);
}
