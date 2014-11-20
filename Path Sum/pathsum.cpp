
#include <iostream>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
			sum_t = sum;
			if(root==NULL)return false;
		return 	forward(root,0);
    }
	bool forward(TreeNode *node,int psum)
	{
		if(node == NULL)
		{
			return false;
		}
		node->val = psum + node->val;
		if(node->left==NULL && node->right == NULL)
		return node->val  == sum_t;
		return forward(node->left,node->val)||forward(node->right,node->val);	
	}
	private:
	int sum_t;
};

