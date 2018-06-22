#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/22

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
