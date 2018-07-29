package main

import "fmt"

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func CreateList(array []int) (head *ListNode) {
	if len(array) == 0 {
		return
	}
	head = &ListNode{array[0], nil}
	pre := head
	for i, val := range array {
		if i == 0 {
			continue
		}
		cur := &ListNode{val, nil}
		pre.Next = cur
		pre = cur
	}
	return
}

func (head *ListNode) printList() {
	var tmp *ListNode = head
	for tmp != nil {
		fmt.Printf("%d->", tmp.Val)
		tmp = tmp.Next
	}
	fmt.Printf("NULL\n")
}

func reverseList(head *ListNode) *ListNode {
	return head
}

func main() {
	var arr []int = []int{1, 2, 3, 4}
	var head *ListNode = CreateList(arr)
	head.printList()
}
