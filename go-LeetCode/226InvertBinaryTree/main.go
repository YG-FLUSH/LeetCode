package main

import "fmt"

/**
 * Definition for a binary tree node.
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func makeTree(ls []int) *TreeNode {
	if len(ls) == 0 {
		return nil
	}
	var root = TreeNode{ls[0], nil, nil}
	for i, val := range ls {
		if i == 0 {
			continue
		}
		insertNode(&root, &TreeNode{val, nil, nil})
	}
	return &root
}

func insertNode(root *TreeNode, node *TreeNode) bool {
	if node.Val >= root.Val {
		if root.Right == nil {
			root.Right = node
		} else {
			return insertNode(root.Right, node)
		}

	} else {
		if root.Left == nil {
			root.Left = node
		} else {
			return insertNode(root.Left, node)
		}
	}
	return true
}

func (root *TreeNode) printTree() {
	ls := []int{}
	if root != nil {
		var queue = []*TreeNode{root}
		for len(queue) > 0 {
			var node = queue[0]
			ls = append(ls, node.Val)
			queue = queue[1:]
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
	}
	fmt.Println(ls)
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	var tmp = root.Left
	root.Left = root.Right
	root.Right = tmp
	if root.Left != nil {
		invertTree(root.Left)
	}
	if root.Right != nil {
		invertTree(root.Right)
	}
	return root
}

func main() {
	var ls = []int{4, 2, 7, 1, 3, 6, 9}
	fmt.Println(ls)
	root := makeTree(ls)
	root.printTree()
	root = invertTree(root)
	root.printTree()
}
