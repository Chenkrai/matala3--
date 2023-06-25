#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i in a heap
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a heap from an array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node in reverse order
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to print the k largest values from the heap
void printKLargest(int arr[], int n, int k) {

    if (k > n) {  // If k is greater than n, we will end the program
        printf("Error: k is larger than the size of the heap.\n");
        return;
    }

    // Create a temporary array of size k
    int* tempArr = (int*)malloc(k * sizeof(int));

    // Copy the first k elements from the heap to the temporary array
    for (int i = 0; i < k; i++) {
        tempArr[i] = arr[i];
    }

    // Build a heap from the temporary array
    buildHeap(tempArr, k);

    int root = 0; // The largest number in the heap

    // Process the remaining elements in the heap
    for (int i = k; i < n; i++) {
        // If the current element is larger than the smallest element in the temporary array
        if (arr[i] > tempArr[root]) {
            // Replace the smallest element in the temporary array with the current element
            tempArr[root] = arr[i];
        }
    }

    // Print the k largest values
    printf("The %d largest values are:\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("\n");

    free(tempArr);
}

int main() {
    int arr[300]; // o(1)

    srand(time(NULL));   // Initialization

    // Generate 300 random numbers
    for (int i = 0; i < 300; i++) {   // o(1)
        arr[i] = rand();  // Generate random numbers
    }

    // Build a heap from the array
    buildHeap(arr, 300); // o(n)

    int k;
    printf("Please enter some k value: ");
    scanf("%d", &k);

    // Print the k largest values from the heap
    printKLargest(arr, 300, k); // o(k * log k)
    return 0;

    // run time: o(1) + o(1) + o(n) + o(klogk) = o(klogk)

}
