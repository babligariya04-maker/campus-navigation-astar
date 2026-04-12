#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "astar.h"
#include "campus.h"

static void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void print_banner(void)
{
    printf("\n");
    printf("  +----------------------------------------------+\n");
    printf("  |        UNIVERSITY CAMPUS NAVIGATION          |\n");
    printf("  |        A* Campus Pathfinder  Phase 2         |\n");
    printf("  +----------------------------------------------+\n\n");
}

static void list_buildings(const Graph *g)
{
    printf("\n  -- Buildings ----------------------------------\n");
    for (int i = 0; i < g->num_nodes; i++)
        printf("  [%2d]  %s\n", i, g->nodes[i].name);
    printf("\n");
}

static int read_node(const Graph *g, const char *prompt)
{
    int id;
    while (1) {
        printf("  %s (0-%d): ", prompt, g->num_nodes - 1);
        if (scanf("%d", &id) == 1 && id >= 0 && id < g->num_nodes) {
            clear_input();
            return id;
        }
        printf("  Invalid. Try again.\n");
        clear_input();
    }
}

int main(void)
{
    Graph *g = graph_create();
    campus_build(g);
    print_banner();
    list_buildings(g);

    printf("  NOTE: Multi-stop routing and road blocking\n");
    printf("  will be added in Phase 3.\n\n");

    int src = read_node(g, "Enter Start Building ID  ");
    int dst = read_node(g, "Enter Destination ID     ");

    printf("\n  Finding shortest path from %s to %s...\n",
           g->nodes[src].name, g->nodes[dst].name);

    Path p;
    if (astar(g, src, dst, &p))
        path_print(g, &p);
    else
        printf("  [!] No path found.\n");

    graph_destroy(g);
    return 0;
}