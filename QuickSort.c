#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    // Initialize pivot to the first element
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // Find the first element greater than the pivot from the left
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // Find the first element smaller than the pivot from the right
        while (j >= low && arr[j] > pivot) {
            j--;
        }

        // Swap elements if needed
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at index `j`
    swap(&arr[low], &arr[j]);

    // Return the partition index
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Call partition function to get the partition index
        int pi  = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
