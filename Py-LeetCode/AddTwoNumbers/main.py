#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/02
# Definition for singly-linked list.


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def print_ls(self):
        node = self
        while(node):
            print node.val
            node = node.next

class Solution(object):

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        lnum1 = self.list_to_num(l1)
        lnum2 = self.list_to_num(l2)
        return self.num_to_list(lnum1 + lnum2)

    def list_to_num(self, ls):
        node = ls
        i = 1
        num = 0
        while(node):
            num = num + int(node.val) * i
            i = i * 10
            node = node.next
        return num

    def num_to_list(self, num):
        num = str(num)
        l = len(num)
        node = head = ListNode(int(num[l-1]))
        num = reversed(num)
        for i, n in enumerate(num):
            if i == 0:
                continue
            node.next = ListNode(int(n))
            node = node.next
        return head


def gen_list(num):
    return Solution().num_to_list(num)

if __name__ == "__main__":
    Solution().addTwoNumbers(gen_list(243), gen_list(564)).print_ls()

