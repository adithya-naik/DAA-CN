#include <stdio.h>

int main() {
    int n, ne = 1, i, j;
    int c[10][10], t[10] = {0};
    int mini, minc = 0, a, b, x, y;

    // Input: Number of vertices
    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    // Input: Cost matrix
    printf("Enter Matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0) {
                c[i][j] = 999;  // Replace 0 with "infinity"
            }
        }
    }

    // Prim's Algorithm Initialization
    t[1] = 1; // Start with vertex 1
    while (ne < n) {
        mini = 999;

        // Find the minimum cost edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (c[i][j] < mini) { // Check for minimum cost
                    if (t[i] != 0) {  // Ensure one endpoint is in MST
                        mini = c[i][j];
                        a = x = i;
                        b = y = j;
                    }
                }
            }
        }

        // Add the edge to the MST if one endpoint is not in the tree
        if (t[x] == 0 || t[y] == 0) {
            printf("%d Edge(%d,%d)=%d\n", ne++, a, b, mini);
            minc += mini;   // Add cost to total
            t[b] = 1;       // Mark vertex as included
        }

        // Mark edge as processed
        c[a][b] = c[b][a] = 999;
    }

    // Output: Total cost of MST
    printf("Total Cost=%d", minc);
}
