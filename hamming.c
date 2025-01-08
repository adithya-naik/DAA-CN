#include <stdio.h>
#include <math.h>

// Function to check if a number is a power of two
int isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}

// Function to calculate parity for a given position
int calculateParity(int hammingCode[], int totalBits, int parityPosition) {
    int parity = 0;
    for (int i = 0; i < totalBits; i++) {
        if (((i + 1) & (parityPosition + 1)) != 0) {
            parity ^= hammingCode[i];
        }
    }
    return parity;
}

// Main function
int main() {
    int dataSize;
    printf("Enter the number of data bits: ");
    scanf("%d", &dataSize);

    int data[dataSize];
    printf("Enter %d data bits (0s and 1s): ", dataSize);
    for (int i = 0; i < dataSize; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the number of parity bits required
    int parityBits = 0;
    while (pow(2, parityBits) < dataSize + parityBits + 1) {
        parityBits++;
    }

    int totalBits = dataSize + parityBits;
    int hammingCode[totalBits];

    // Initialize Hamming Code with 0
    for (int i = 0, dataIndex = 0; i < totalBits; i++) {
        if (isPowerOfTwo(i + 1)) {
            hammingCode[i] = 0; // Parity bit placeholder
        } else {
            hammingCode[i] = data[dataIndex++]; // Data bit
        }
    }

    // Calculate parity bits
    for (int i = 0; i < parityBits; i++) {
        int parityPosition = (int)pow(2, i) - 1;
        hammingCode[parityPosition] = calculateParity(hammingCode, totalBits, parityPosition);
    }

    // Print the generated Hamming Code
    printf("Generated Hamming Code: ");
    for (int i = 0; i < totalBits; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");

    // Error detection and correction
    int receivedCode[totalBits];
    printf("Enter received Hamming Code (with/without error): ");
    for (int i = 0; i < totalBits; i++) {
        scanf("%d", &receivedCode[i]);
    }

    // Detect error position
    int errorPosition = 0;
    for (int i = 0; i < parityBits; i++) {
        int parityPosition = (int)pow(2, i) - 1;
        int parity = calculateParity(receivedCode, totalBits, parityPosition);
        if (parity != 0) {
            errorPosition += (parityPosition + 1);
        }
    }

    if (errorPosition == 0) {
        printf("No error detected.\n");
    } else {
        printf("Error detected at bit position: %d\n", errorPosition);
        receivedCode[errorPosition - 1] ^= 1; // Correct the error
        printf("Corrected Hamming Code: ");
        for (int i = 0; i < totalBits; i++) {
            printf("%d", receivedCode[i]);
        }
        printf("\n");
    }

    return 0;
}
