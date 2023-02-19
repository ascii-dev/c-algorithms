#ifndef ASCII_PQ
#define ASCII_PQ

#define queueCapacity 1000;

typedef struct MaxHeap {
    int size, capacity;
    int tree[1000];
} MaxHeap;

MaxHeap *construct_mh();
void destroy_mh(MaxHeap *mh);
void siftUp(MaxHeap *mh, int index);
void siftDown(MaxHeap *mh, int index);
void insert(MaxHeap *mh, int value);
int getMax(MaxHeap *mh);
int getSize(MaxHeap *mh);
int isEmpty(MaxHeap *mh);
int extractMax(MaxHeap *mh);
int remove_mh(MaxHeap *mh, int index);
void heapify(int *numbers, int size);
void heapSort(int *numbers, int size);

#endif
