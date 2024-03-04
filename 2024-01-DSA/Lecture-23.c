#include <stdio.h>

#define MAX_HEAP_SIZE 100

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform max heapify operation
void maxHeapify(int heap[], int size, int parent) {
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    int largest = parent;
    if (leftChild < size && heap[leftChild] > heap[largest])
        largest = leftChild;
    if (rightChild < size && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != parent) {
        swap(&heap[parent], &heap[largest]);
        maxHeapify(heap, size, largest); // Recursively heapify the affected subtree
    }
}

// Function to insert an element into the max heap
void insertElement(int heap[], int *size, int value) {
    if (*size == MAX_HEAP_SIZE) {
        printf("Heap is full. Insertion failed.\n");
        return;
    }

    int i = (*size)++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the maximum element from the max heap
int deleteMax(int heap[], int *size) {
    if (*size <= 0)
        return -1; // Indicates empty heap

    int max = heap[0];
    heap[0] = heap[--(*size)];
    maxHeapify(heap, *size, 0);

    return max;
}

int main() {
    int heap[MAX_HEAP_SIZE];
    int size = 0;
    int input;

    printf("Enter positive integers (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1)
            break;
        if (size < MAX_HEAP_SIZE) {
            insertElement(heap, &size, input);
            // Display heap after every insertion
            printf("Heap: \t");
            for (int i = 0; i < size; i++)
                printf("%d ", heap[i]);
            printf("\n");
        } else {
            printf("Heap is full. Ignoring input.\n");
        }
    }
    
    // Deleting maximum element from heap
    int max = deleteMax(heap, &size);
    if (max != -1)
        printf("Maximum element deleted: %d\n", max);
    else
        printf("Heap is empty. Deletion failed.\n");

    printf("Heap after deleting maximum element:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");

    return 0;
}
