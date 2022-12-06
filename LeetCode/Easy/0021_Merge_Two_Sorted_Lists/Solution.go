package main

type ListNode struct {
	Val  int
	Next *ListNode
}

//2022-03-07
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	var newHead, newTail *ListNode = nil, nil

	for list1 != nil && list2 != nil {
		if newHead == nil {
			if list1.Val <= list2.Val {
				newHead = list1
				newTail = list1
				list1 = list1.Next
			} else {
				newHead = list2
				newTail = list2
				list2 = list2.Next
			}
		} else {
			if list1.Val <= list2.Val {
				newTail.Next = list1
				list1 = list1.Next
			} else {
				newTail.Next = list2
				list2 = list2.Next
			}
			newTail = newTail.Next
		}
	}

	if list1 != nil {
		newTail.Next = list1
	}
	if list2 != nil {
		newTail.Next = list2
	}

	return newHead
}
