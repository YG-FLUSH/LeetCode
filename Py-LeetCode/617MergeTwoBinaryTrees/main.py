#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/22
# Definition for a binary tree node.
import sys
sys.path.append("..")
from utils import list_to_tree


class Solution(object):

    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1:
            return t2
        if not t2:
            return t1

        _queue = [(t1, t2)]
        while True:
            if not _queue:
                break
            _1node, _2node = _queue.pop()
            if _1node.val is None and _2node.val is None:
                _1node.val = None
                continue

            if _1node.val is None:
                _1node_val = 0
            else:
                _1node_val = _1node.val
            if _2node.val is None:
                _2node_val = 0
            else:
                _2node_val = _2node.val
            _1node.val = _1node_val + _2node_val

            if _1node.left and _2node.left:
                _queue.append((_1node.left, _2node.left))
            elif not _1node.left and _2node.left:
                _1node.left = _2node.left

            if _1node.right and _2node.right:
                _queue.append((_1node.right, _2node.right))
            elif not _1node.right and _2node.right:
                _1node.right = _2node.right

        return t1


if __name__ == "__main__":
    _1ls = [1,3,2,5]
    _1tree = list_to_tree(_1ls)
    _2ls = [2,1,3,None,4,None,7]
    _2tree = list_to_tree(_2ls)
    _tree= Solution().mergeTrees(_1tree, _2tree)
    _tree.print_tree()



