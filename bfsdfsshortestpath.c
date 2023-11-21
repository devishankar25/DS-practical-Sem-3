#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Structure for representing an adjacency list node
struct Node {
 int vertex;
 struct Node* next;
};
// Structure for representing a graph
struct Graph {
 int numVertices;
 struct Node* adjacencyList[MAX_VERTICES];
};
// Function to create a new graph with a given number of 
// vertices
struct Graph* createGraph(int vertices) {
 struct Graph* graph = (struct Graph*)malloc(sizeof(struct
Graph));
 graph->numVertices = vertices;
 for (int i = 0; i < vertices; i++) {
 graph->adjacencyList[i] = NULL;
 }
 return graph;
}
// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
 newNode->vertex = dest;
 newNode->next = graph->adjacencyList[src];
 graph->adjacencyList[src] = newNode;
 newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->vertex = src;
 newNode->next = graph->adjacencyList[dest];
 graph->adjacencyList[dest] = newNode;
}
// Breadth-First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
 int visited[MAX_VERTICES] = {0}; // Initialize all vertices as not 
// visited
 int queue[MAX_VERTICES];
 int front = 0, rear = 0;
 visited[startVertex] = 1;
 queue[rear++] = startVertex;
 printf("Breadth-First Search starting from vertex %d: ", 
startVertex);
 while (front < rear) {
 int currentVertex = queue[front++];
 printf("%d ", currentVertex);
 struct Node* temp = graph->adjacencyList[currentVertex];
 while (temp) {
 int adjVertex = temp->vertex;
 if (!visited[adjVertex]) {
 visited[adjVertex] = 1;
 queue[rear++] = adjVertex;
 }
 temp = temp->next;
 }
 }
 printf("\n");
}
// Depth-First Search (DFS)
void DFS(struct Graph* graph, int vertex, int visited[]) {
 visited[vertex] = 1;
 printf("%d ", vertex);
 struct Node* temp = graph->adjacencyList[vertex];
 while (temp) {
 int adjVertex = temp->vertex;
 if (!visited[adjVertex]) {
 DFS(graph, adjVertex, visited);
 }
 temp = temp->next;
 }
}
// Function to initiate DFS traversal
void startDFS(struct Graph* graph, int startVertex) {
 int visited[MAX_VERTICES] = {0}; // Initialize all vertices as not 
// visited
 printf("Depth-First Search starting from vertex %d: ", 
startVertex);
 DFS(graph, startVertex, visited);
 printf("\n");
}
int main() {
 struct Graph* graph = createGraph(6);
 addEdge(graph, 0, 1);
 addEdge(graph, 0, 2);
 addEdge(graph, 1, 3);
 addEdge(graph, 2, 4);
 addEdge(graph, 3, 5);
 BFS(graph, 0);
 startDFS(graph, 0);
 return 0;
}