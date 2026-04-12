#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 12
#define INF 1e9

typedef struct Edge {
    int         to;
    float       weight;
    char        road_name[64];
    int         blocked;
    struct Edge *next;
} Edge;

typedef struct {
    int   id;
    char  name[64];
    float x, y;
} Node;

typedef struct {
    Node  nodes[MAX_NODES];
    Edge *adj[MAX_NODES];
    int   num_nodes;
} Graph;

Graph *graph_create(void);
void   graph_destroy(Graph *g);
void   graph_add_edge(Graph *g, int from, int to,
                      float weight, const char *road_name);
void   graph_block_road(Graph *g, const char *road_name, int blocked);
void   graph_print(const Graph *g);

#endif