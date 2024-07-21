package main

import (
	"container/heap"
	"fmt"
)

type Stack struct {
	elements []int
}

func (s *Stack) Push(value int) {
	s.elements = append(s.elements, value)
}

func (s *Stack) Pop() int {
	if len(s.elements) == 0 {
		return -1 // or any other error handling
	}
	val := s.elements[len(s.elements)-1]
	s.elements = s.elements[:len(s.elements)-1]
	return val
}

func reverse(s string) string {
	// rune is substitue for char
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		// no swap(x,y) in go need to write manually
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

type Item struct {
	value    string
	priority int
	index    int
}

// A PriorityQueue implements heap.Interface and holds Items
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority // Min-heap based on priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	fmt.Println("Go syntax learning")
	s := "hello"
	i := 42
	fmt.Printf("%q\n", s)  // Quoted string "hello"
	fmt.Printf("%p\n", &s) // Pointer
	fmt.Printf("%X\n", i)  // Integer in base 16
	// 	%T: Type of the value.
	// %%: A literal percent sign.
	// %t: The word true or false.
	// %b: Base 2.
	items := []*Item{
		{value: "task1", priority: 3}, {value: "task2", priority: 1}, {value: "task3", priority: 2},
	}

	pq := make(PriorityQueue, len(items))
	for i, item := range items {
		pq[i] = item
	}
	heap.Init(&pq)

	item := &Item{
		value:    "task4",
		priority: 0,
	}
	heap.Push(&pq, item)

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		fmt.Printf("%.2d:%s ", item.priority, item.value)
	}
}
