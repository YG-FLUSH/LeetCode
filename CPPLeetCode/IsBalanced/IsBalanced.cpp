#include <iostream>
#include <algorithm>
using namespace std;
/*Definition for binary tree*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isBalanced(TreeNode *root) 
	{
		satisfaction =true;
		NodeDepth(root);
		return satisfaction;
    }
	int NodeDepth(TreeNode *node)
	{
			if(!satisfaction)	return 1;
			if(node == NULL)return -1;
			int left = NodeDepth(node->left);
			int right = NodeDepth(node->right);
			if(abs(left-right)>1)
			satisfaction = false;
			return  max<int>(left,right)+1;
	}
	private:
	bool satisfaction;
};
int main()
{
	
	return 0;
}