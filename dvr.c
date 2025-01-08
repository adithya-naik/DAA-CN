#include <stdio.h>
#define MAX_NODES 10
#define INF 9999

// Distance vector routing implementation
void distanceVectorRouting(int costMatrix[MAX_NODES][MAX_NODES], int nodes) {
    int distance[MAX_NODES][MAX_NODES];
    int nextHop[MAX_NODES][MAX_NODES];

    // Initialize distance and next hop tables
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            distance[i][j] = costMatrix[i][j];
            if (costMatrix[i][j] != INF && i != j) {
                nextHop[i][j] = j;
            } else {
                nextHop[i][j] = -1;
            }
        }
    }

    // Distance vector computation
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }

    // Print the distance vector table
    printf("Distance Vector Table:\n");
    for (int i = 0; i < nodes; i++) {
        printf("From Node %d:\n", i);
        printf("Destination\tCost\tNext Hop\n");
        for (int j = 0; j < nodes; j++) {
            if (i != j) {
                printf("%d\t\t%d\t\t%d\n", j, distance[i][j], nextHop[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int nodes;
    int costMatrix[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes in the subnet: ");
    scanf("%d", &nodes);

    printf("Enter the cost adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    distanceVectorRouting(costMatrix, nodes);

    return 0;
}
