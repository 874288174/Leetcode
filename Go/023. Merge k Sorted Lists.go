func mergeKLists(lists []*ListNode) *ListNode {
	pq := make(PQ, 0)
	for _, node := range lists {
		if node != nil {
			pq = append(pq, node)
		}
	}

	if len(pq) == 0 {
		return nil
	}
	heap.Init(&pq)

	head := &ListNode{}
	dummyHead := head

	for len(pq) > 0 {
		min := heap.Pop(&pq)
		minNode := min.(*ListNode)
		head.Next = minNode
		head = head.Next

		if minNode.Next != nil {
			heap.Push(&pq, minNode.Next)
		}
	}
	return dummyHead.Next
}

type PQ []*ListNode

func (pq PQ) Len() int {
	return len(pq)
}

func (pq PQ) Swap(a, b int) {
	pq[a], pq[b] = pq[b], pq[a]
}

func (pq PQ) Less(a, b int) bool {
	return pq[a].Val < pq[b].Val
}

func (pq *PQ) Push(x interface{}) {
	node := x.(*ListNode)
	*pq = append(*pq, node)
}

func (pq *PQ) Pop() interface{} {
	old := *pq
	lastNode := old[len(*pq)-1]
	*pq = old[:len(*pq)-1]
	return lastNode
}