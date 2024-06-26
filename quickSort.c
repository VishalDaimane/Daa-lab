#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array using the last element as the pivot
int partition(int arr[], int start, int end) {
    int pivot = arr[end]; // Choose the last element as the pivot
    int i = (start - 1); // Index of the smaller element

    for (int j = start; j <= end - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of the smaller element
            swap(&arr[i], &arr[j]); // Swap the elements
        }
    }
    swap(&arr[i + 1], &arr[end]); // Swap the pivot element with the element at i+1 position
    return (i + 1); // Return the partitioning index
}

// Function to implement QuickSort
void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end); // Partition the array
        quicksort(arr, start, p - 1); // Recursively sort the elements before the partition
        quicksort(arr, p + 1, end); // Recursively sort the elements after the partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {13, 18, 27, 2, 19, 25}; // Initialize the array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    printf("Before sorting array elements are - \n");
    printArray(arr, n); // Print the original array

    quicksort(arr, 0, n - 1); // Sort the array using QuickSort

    printf("After sorting array elements are - \n");
    printArray(arr, n); // Print the sorted array

    return 0;
}
