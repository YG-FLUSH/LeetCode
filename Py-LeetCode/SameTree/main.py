#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/13

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def print_tree(self):
        # 层次遍历
        tmp_queue = [self]
        buf = [self.val]
        while tmp_queue:
            node = tmp_queue.pop()
            if node.left:
                tmp_queue.append(node.left)
                buf.append(node.left.val)
            if node.right:
                tmp_queue.append(node.right)
                buf.append(node.right.val)
        print buf


class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p is None or q is None:
            if p != q:
                return False

            if p == q:
                return True

        if p.val != q.val:
            return False

        if p.left != None:
            if q.left != None:
                if not self.isSameTree(p.left, q.left):
                    return False
            else:
                return False

        elif q.left != None:
            return False

        if p.right != None:
            if q.right != None:
                if not self.isSameTree(p.right, q.right):
                    return False
            else:
                return False
        elif q.right != None:
            return False

        return True


def list_to_tree(ls):
    if not ls:
        return TreeNode(None)
    i = 0
    root = TreeNode(ls[i])
    tmp_queue = [root]
    while tmp_queue:
        i += 1
        node = tmp_queue.pop()
        if not node.val:
            continue

        if 2*i -1 >= len(ls):
            return root
        node.left = TreeNode(ls[2*i-1])
        tmp_queue.append(node.left)

        if 2*i >= len(ls):
            return root
        node.right = TreeNode(ls[2*i])
        tmp_queue.append(node.right)
    return root

if __name__ == "__main__":
    p = list_to_tree([1, 2, 3, None, 1])
    p = list_to_tree([])
    p.print_tree()
    q = list_to_tree([1, 2, 3, None, 1])
    q = list_to_tree([])
    q.print_tree()
    print Solution().isSameTree(p, q)
