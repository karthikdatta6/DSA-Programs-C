//BFS
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void bfs(int adj[MAX][MAX], int V, int start_vertex) {
    int q[MAX], curr, front = 1, rear = 0;    

    
    int visited[MAX] = {0};// Initially mark all the vertices as not visited

    // Mark the source node as visited and enqueue it
    visited[start_vertex] = 1;
    q[++rear] = start_vertex;

    
    while (front <= rear) {
         // Dequeue a vertex and print it
         curr = q[front++];
         printf("%d -> ", curr);
    
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int i = 1; i <= V; i++) {
            if (adj[curr][i] == 1 && visited[i]==0) {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  // Undirected graph
}

int main() {
    
    int V = 5;// Number of vertices in the graph
    
    int adj[MAX][MAX] = {0}; // Adjacency matrix initialized with 0
   
    // Add edges to the graph
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    
    // Perform BFS traversal starting from vertex 0
    printf("BFS starting from 1:\n");
    bfs(adj, V, 5);
    
    return 0;
}
