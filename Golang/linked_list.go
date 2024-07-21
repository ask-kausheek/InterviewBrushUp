package main

import "fmt"

// Node represents a single node in the linked list
type Node struct {
	Value int
	Next  *Node
}

// LinkedList represents the linked list itself
type LinkedList struct {
	Head *Node
}

// InsertAtBeginning adds a new node at the beginning of the list
func (ll *LinkedList) InsertAtBeginning(value int) {
	newNode := &Node{Value: value}
	newNode.Next = ll.Head // . in Go and -> in cpp
	ll.Head = newNode
}

// InsertAtEnd adds a new node at the end of the list
func (ll *LinkedList) InsertAtEnd(value int) {
	newNode := &Node{Value: value}
	if ll.Head == nil {
		ll.Head = newNode
		return
	}
	current := ll.Head
	for current.Next != nil {
		current = current.Next
	}
	current.Next = newNode
}

// DeleteNode removes the first occurrence of a node with the given value
func (ll *LinkedList) DeleteNode(value int) {
	if ll.Head == nil {
		return
	}
	if ll.Head.Value == value {
		ll.Head = ll.Head.Next
		return
	}
	current := ll.Head
	for current.Next != nil && current.Next.Value != value {
		current = current.Next
	}
	if current.Next != nil {
		current.Next = current.Next.Next
	}
}

// PrintList prints all the nodes in the linked list
func (ll *LinkedList) PrintList() {
	current := ll.Head
	for current != nil {
		fmt.Print(current.Value, " ")
		current = current.Next
	}
	fmt.Println()
}

func LinkedListtest() {
	ll := &LinkedList{}

	ll.InsertAtBeginning(3)
	ll.InsertAtBeginning(2)
	ll.InsertAtEnd(4)
	ll.InsertAtEnd(5)

	fmt.Println("Linked List:")
	ll.PrintList() // Output: 2 3 4 5

	ll.DeleteNode(4)
	fmt.Println("After deleting 4:")
	ll.PrintList() // Output: 2 3 5
}
