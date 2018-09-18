#pragma once
#include<iostream>
#ifndef TYPES_H
#define TYPES_H


struct ELEMENT
{
	int key;
};

struct HEAP
{
	int capacity;
	int size;
	ELEMENT* H;
};

HEAP* Initialize(int n);
void Min_Heapify(HEAP *heap, int i);
void BuildHeap(HEAP* heap, ELEMENT A[]);
void Insert(HEAP *heap, int k);
int DeleteMin(HEAP *heap);
void DecreaseKey(HEAP *heap, int index, int value);
void PrintHeap(HEAP *heap);

#endif

