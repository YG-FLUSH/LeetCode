#!/usr/bin/env python

class ListLinkError(Exception):
	pass

class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class ListLink:

	def __init__(self, arr):
		self.head = None
		if not arr:
			return None
		if not isinstance(arr, list):
			return None
		self.head = ListNode(arr[0])
		now = self.head
		for v in range(1, len(arr)):
			node = ListNode(arr[v])
			now.next = node
			now = node

	def show(self):
		if not self.head:
			raise ListLinkError("head is None")
		nnode = self.head
		while nnode is not None:
			print nnode.val
			nnode = nnode.next

if __name__ == "__main__":
	arr = [1, 2]
	link = ListLink(arr)
	link.show()








