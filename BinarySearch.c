#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int left = 0;          // Starting index
    int right = n - 1;     // Ending index

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find the middle index

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid;  // Return the index of the key
        }

        // If key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1;  // Return -1 if the key is not present in the array
}

int main() {
    int n, key;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements of the array from the user
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);  // Element found
    } else {
        printf("Element not found\n");  // Element not found
    }

    return 0;
}
