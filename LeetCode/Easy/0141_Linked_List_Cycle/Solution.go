package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	single, double := head, head.Next
	for single != nil && double != nil {
		if single == double || single == double.Next {
			return true
		}

		single = single.Next
		double = double.Next
		if double != nil {
			double = double.Next
		}
	}
	return false
}
