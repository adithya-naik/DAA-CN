#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i = left;   // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;   // Starting index to be sorted
    int temp[right - left + 1]; // Temporary array to store merged result

    // Merge the two subarrays into temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k - left] = arr[i];
            i++;
        } else {
            temp[k - left] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k - left] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k - left] = arr[j];
        j++;
        k++;
    }

    // Copy the merged subarray back into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}
 
// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Mid point of the array

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
