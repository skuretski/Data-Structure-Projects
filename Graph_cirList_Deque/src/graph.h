/*
 * graph.h
 *
 *  Created on: Mar 12, 2015
 *  Author: Susie Kuretski
 */

#ifndef GRAPH_DEFINED
#define GRAPH_DEFINED 1

struct Vertex {
	char label;
	int isVisited; /* This boolean indicates where you have been */
	int numNeighbors;
	struct Vertex** neighbors; /* Array of pointers to Vertex which are adjacent to THIS */
};
typedef struct Vertex Vertex;

struct Graph {
	int numEdges;
	int numVertices;
	Vertex* vertexSet; /* Array of Vertex which store the structure of the graph*/
};
typedef struct Graph Graph;

/* Some functions to create various graphs for testing */
void createGraph1(Graph* g);
void createGraph2(Graph* g);
void createGraph3(Graph* g);
void createGraph4(Graph* g);
void createGraph5(Graph* g);

/* Utilities to construct and view graphs */
void setupVertices(Graph* g);
void setupEdge(Graph *g, Vertex* first, Vertex* second);
void printGraph(Graph* g);

/* Utilities to help analyze graph structure*/
int isAdjacent(Vertex* firstVert, Vertex* secondVert);

/* Search related functions */
void clearVisited(Graph* g);
int DFS(Graph* g, Vertex* source, Vertex* destination);
int DFSRecursive(Graph* g, Vertex* source, Vertex* destination);
int BFS(Graph* g, Vertex* source, Vertex* destination);

#endif
