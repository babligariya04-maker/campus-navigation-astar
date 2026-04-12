#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"

#define MAX_PATH 256

typedef struct {
    int   nodes[MAX_PATH];
    char  roads[MAX_PATH][64];
    float dists[MAX_PATH];
    int   length;
    float total_dist;
} Path;

int  astar(const Graph *g, int start, int goal, Path *out);
void path_print(const Graph *g, const Path *p);

#endif