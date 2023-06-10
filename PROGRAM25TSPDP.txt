#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[MAX_SIZE][MAX_SIZE], int n, int start, int visited_all) {
    int i, mask, cost, min_cost = INT_MAX;

    // Base case: if all cities have been visited
    if (visited_all == (1 << n) - 1) {
        return graph[start][0];  // Return to the starting city
    }

    // Try all unvisited cities as next destinations
    for (i = 0; i < n; i++) {
        mask = 1 << i;

        // Check if the city has already been visited
        if ((visited_all & mask) == 0) {
            // Mark the city as visited
            visited_all |= mask;

            // Recursive call to calculate the cost of visiting remaining cities
            cost = graph[start][i] + tsp(graph, n, i, visited_all);

            // Update the minimum cost
            min_cost = min(min_cost, cost);

            // Mark the city as unvisited for other paths
            visited_all &= ~mask;
        }
    }

    return min_cost;
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE];
    int n, i, j, start;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting city: ");
    scanf("%d", &start);

    int visited_all = 1 << n;  // Mark all cities as unvisited except the starting city

    int min_cost = tsp(graph, n, start, visited_all);

    printf("Minimum cost: %d\n", min_cost);

    return 0;
}
