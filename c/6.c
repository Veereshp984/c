#include <stdio.h>

int main() {
    int nodes, cost[10][10];

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    // Input cost matrix
    printf("Enter cost matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Display router table
    for (int i = 0; i < nodes; i++) {
        printf("Router %d:\n", i + 1);
        for (int j = 0; j < nodes; j++) {
            printf("Node %d via %d, Cost: %d\n", j + 1, i + 1, cost[i][j]);
        }
    }

    return 0;
}
