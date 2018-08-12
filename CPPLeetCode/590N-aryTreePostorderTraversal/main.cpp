// Definition for a Node.
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        this->_postorder(root, &result);
        return result;
    }
private:
    void _postorder(Node *root, vector<int> *result){
        if (root == NULL){
            return ;
        }
        vector<Node*>::iterator iend =  root->children.end();
        for(auto i=root->children.begin(); i < iend; ++i){
            this->_postorder(*i, result);
        }
        result->push_back(root->val);
        return ;
    }
};

int main(){
    Node* root = Node.create_root();
    Solution().postorder(root);
}
