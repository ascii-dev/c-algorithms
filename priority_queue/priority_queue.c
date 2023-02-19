#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "priority_queue.h"

MaxHeap *construct_mh() {
    MaxHeap *new_mh = malloc(sizeof(MaxHeap));
    new_mh->size = 0;
    new_mh->capacity = 1000;

    return new_mh;
}

void destroy_mh(MaxHeap *mh) {
    free(mh);
}

int parent(int index) {
    return index / 2;
}

int leftChild(int index) {
    return (index * 2) + 1;
}

int rightChild(int index) {
    return (index * 2) + 2;
}

void siftUp(MaxHeap *mh, int index) {
    int parentIndex = parent(index);
    int i = index;
    while (i > 1 && mh->tree[parentIndex] < mh->tree[i]) {
        int temp = mh->tree[parentIndex];
        mh->tree[parentIndex] = mh->tree[i];
        mh->tree[i] = temp;

        i = parentIndex;
    }
}

void siftDown(MaxHeap *mh, int index) {
    int maxIndex = index;

    int leftIndex = leftChild(index);
    if (leftIndex < mh->size && mh->tree[leftIndex] > mh->tree[maxIndex])
        maxIndex = leftIndex;

    int rightIndex = rightChild(index);
    if (rightIndex < mh->size&& mh->tree[rightIndex] > mh->tree[maxIndex])
        maxIndex = rightIndex;

    if (index != maxIndex) {
        int temp = mh->tree[maxIndex];
        mh->tree[maxIndex] = mh->tree[index];
        mh->tree[index] = temp;

        siftDown(mh, maxIndex);
    }
}

void insert(MaxHeap *mh, int value) {
    if (mh->size == mh->capacity) {
        printf("Heap is full");
        exit(1);
    }

    mh->size++;
    mh->tree[mh->size] = value;
    siftUp(mh, mh->size);
}

int getMax(MaxHeap *mh) {
    if (mh->size == 0) {
        printf("Heap is empty");
        exit(1);
    }

    return mh->tree[0];
}

int getSize(MaxHeap *mh) {
    return mh->size;
}

int isEmpty(MaxHeap *mh) {
    return (mh->size == 0) ? 1 : 0;
}

int extractMax(MaxHeap *mh) {
    if (mh->size == 0) {
        printf("Heap is empty");
        exit(1);
    }

    int result = mh->tree[0];
    mh->tree[0] = mh->tree[mh->size--];
    siftDown(mh, 0);

    return result;
}

int remove_mh(MaxHeap *mh, int index) {
    if (mh->size == 0) {
        printf("Heap is empty");
        exit(1);
    }

    if (index < 0 || index > mh->size) {
        printf("Invalid index ix supplied");
        exit(1);
    }

    int result = mh->tree[index];
    mh->tree[index] = INT_MAX;
    siftUp(mh, index);
    extractMax(mh);

    return result;
}


void _siftDown(int *numbers, int size, int index) {
    int maxIndex = index;

    int leftIndex = leftChild(index);
    if (leftIndex < size && numbers[leftIndex] > numbers[maxIndex])
        maxIndex = leftIndex;

    int rightIndex = rightChild(index);
    if (rightIndex < size&& numbers[rightIndex] > numbers[maxIndex])
        maxIndex = rightIndex;

    if (index != maxIndex) {
        int temp = numbers[maxIndex];
        numbers[maxIndex] = numbers[index];
        numbers[index] = temp;

        _siftDown(numbers, size, maxIndex);
    }
}

void heapify(int *numbers, int size) {
    for (int i = size/2; i > 0; i--)
        _siftDown(numbers, size, i);
}

void heapSort(int *numbers, int size) {
    heapify(numbers, size);
    
    for (int i = size - 1; i > 0; --i) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;

        _siftDown(numbers, i, 0);
    }
}
