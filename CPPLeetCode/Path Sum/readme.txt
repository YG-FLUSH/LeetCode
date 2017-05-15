Path Sum Total Accepted: 20926 Total Submissions: 68331 My Submissions
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

思路：
前序遍历一次，碰到节点为NULL则进行判断。
每次取值都将父节点的值加进子节点，这样在叶子节点就是其和了。