#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

Graph *graph_create(void)
{
    Graph *g = calloc(1, sizeof(Graph));
    if (!g) { perror("calloc"); exit(1); }
    return g;
}

void graph_destroy(Graph *g)
{
    for (int i = 0; i < g->num_nodes; i++) {
        Edge *e = g->adj[i];
        while (e) {
            Edge *tmp = e->next;
            free(e);
            e = tmp;
        }
    }
    free(g);
}

void graph_add_edge(Graph *g, int from, int to,
                    float weight, const char *road_name)
{
    Edge *e1 = malloc(sizeof(Edge));
    e1->to      = to;
    e1->weight  = weight;
    e1->blocked = 0;
    strncpy(e1->road_name, road_name, sizeof(e1->road_name) - 1);
    e1->road_name[sizeof(e1->road_name)-1] = '\0';
    e1->next    = g->adj[from];
    g->adj[from] = e1;

    Edge *e2 = malloc(sizeof(Edge));
    e2->to      = from;
    e2->weight  = weight;
    e2->blocked = 0;
    strncpy(e2->road_name, road_name, sizeof(e2->road_name) - 1);
    e2->road_name[sizeof(e2->road_name)-1] = '\0';
    e2->next    = g->adj[to];
    g->adj[to]  = e2;
}

void graph_block_road(Graph *g, const char *road_name, int blocked)
{
    int found = 0;
    for (int i = 0; i < g->num_nodes; i++) {
        for (Edge *e = g->adj[i]; e; e = e->next) {
            if (strcmp(e->road_name, road_name) == 0) {
                e->blocked = blocked;
                found = 1;
            }
        }
    }
    if (!found)
        printf("  [!] Road \"%s\" not found in map.\n", road_name);
}

void graph_print(const Graph *g)
{
    printf("\n=== Campus Road Map ===\n");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("  [%2d] %-20s -> ", i, g->nodes[i].name);
        for (Edge *e = g->adj[i]; e; e = e->next) {
            printf("%s (%.0fm%s)  ",
                   g->nodes[e->to].name, e->weight,
                   e->blocked ? ", BLOCKED" : "");
        }
        printf("\n");
    }
    printf("\n");
}