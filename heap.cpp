#include <iostream>
#include <cstdlib>
#include "heap.h"
using namespace std;

HEAP* Initialize(int n)
{
	struct HEAP* h = (struct HEAP*)malloc(sizeof(struct HEAP));
	h->capacity = n;
	h->size = 0;
	h->H = (struct ELEMENT*)malloc(sizeof(struct ELEMENT)*n);
	return h;
}

void Min_Heapify(HEAP *heap, int i)
{
	int left; 
	int right; 
	int smallest;
	left = (2 * i)+1;
	right = (2 * i) + 2;
	if (left < heap->size && heap->H[left].key < heap->H[i].key)
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right < heap->size && heap->H[right].key < heap->H[smallest].key)
		{
			smallest = right;
		}
	if (smallest != i)
	{
		int temp;
		temp = heap->H[i].key;
		heap->H[i].key = heap->H[smallest].key;
		heap->H[smallest].key = temp;
		Min_Heapify(heap, smallest);
	}

}
void BuildHeap(HEAP* heap, ELEMENT A[])
{
	//heap->H = A;
	for (int i = (heap->size) / 2; i >= 0; i--)
	{
		Min_Heapify(heap, i);
	}
}
void Insert(HEAP *heap, int k)
{
	if (heap->size == heap->capacity)
	{
		cout << "Could not insert key, heap is full \n";
	}
	else
	{
		heap->size++;
		int i = heap->H[heap->size].key;
		int  parent = (i - 1) / 2;
		while (i > 1 && heap->H[parent].key > k)
		{
			heap->H[i] = heap->H[parent];
			i = parent;
		}
		heap->H[i].key = k;
	}
}
int DeleteMin(HEAP *heap)
{
	int min;
	if (heap->size < 1) {
		cout << "There are no elements to be removed.";
	}
	else
	{
		min = heap->H[0].key;
		heap->H[0].key = heap->H[heap->size].key;
		heap->size--;
		Min_Heapify(heap, 0);
	}
	return min;
}
void DecreaseKey(HEAP *heap, int index, int value)
{
	int i = heap->H[heap->size].key;
	int parent = (i-1) / 2;
	if (value > heap->H[i].key)
	{
		cout << "The new key is larger than the current key";
	}
	else
	{
		heap->H[i].key = value;
		while (i < 1 && heap->H[parent].key > heap->H[i].key)
		{
			int temp;
			temp = heap->H[parent].key;
			heap->H[parent].key = heap->H[i].key;
			heap->H[i].key = temp;
		}
	}
}

void PrintHeap(HEAP *heap)
{
	cout << "Heap Size: " << heap->size << endl;
	cout << "Capacity: " << heap->capacity << endl;
		for (int i = 0; i = heap->size; i++)
		{
			cout << heap->H[i].key;
		}
}