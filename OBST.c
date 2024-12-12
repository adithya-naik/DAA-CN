#include <stdio.h>
#include <limits.h>

// A utility function to get sum of array elements freq[i] to freq[j]
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

/* A Dynamic Programming based function that calculates
   the minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n) {
    // Create an auxiliary 2D matrix to store results of subproblems
    int cost[n][n];

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Now we need to consider chains of length 2, 3, ... . L is chain length.
    for (int L = 2; L <= n; L++) {
        // i is row number in cost[][]
        for (int i = 0; i <= n - L; i++) {
            // Get column number j from row number i and chain length L
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

// Driver program to test the above functions
int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Cost of Optimal BST is %d\n", optimalSearchTree(keys, freq, n));
    return 0;
}



/*
Cost of Optimal BST is 142
*/
