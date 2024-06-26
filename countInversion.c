#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of the array and count inversions
int merge_and_count(int arr[], int temp[], int left, int mid, int right) {
    int i = left;   // Starting index for left subarray
    int j = mid;    // Starting index for right subarray
    int k = left;   // Starting index to be sorted
    int inv_count = 0;

    // Conditions are checked to ensure that i doesn't exceed mid and j doesn't exceed right
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Since arr[i] > arr[j], there are mid - i inversions, because all elements left to i in the left subarray are greater than arr[j]
            inv_count += (mid - i);
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into Original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Function to use merge sort and count inversions
int merge_sort_and_count(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        // Inversions in the left half
        inv_count += merge_sort_and_count(arr, temp, left, mid);

        // Inversions in the right half
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);

        // Inversions during merging
        inv_count += merge_and_count(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Function to count inversions in the array
int count_inversions(int arr[], int n) {
    int temp[n];
    return merge_sort_and_count(arr, temp, 0, n - 1);
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 3, 2, 1, 5, 6, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    print_array(arr, n);

    printf("Number of inversions: %d\n", count_inversions(arr, n));

    printf("Array: ");
    print_array(arr, n);

    return 0;
}
