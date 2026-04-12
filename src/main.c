#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    printf("  |     GREENFIELD UNIVERSITY  NAVIGATION        |\n");
    printf("  |          A* Campus Pathfinder  v1.0          |\n");
    printf("  +----------------------------------------------+\n\n");
}

static void print_menu(void)
{
    printf("  +-----------------------------+\n");
    printf("  |  1. Find shortest path      |\n");
    printf("  |  2. Multi-stop route        |\n");
    printf("  |  3. Block / unblock a road  |\n");
    printf("  |  4. Show campus map         |\n");
    printf("  |  5. List buildings          |\n");
    printf("  |  0. Exit                    |\n");
    printf("  +-----------------------------+\n");
    printf("  Choice: ");
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
        printf("  Invalid id. ");
        clear_input();
    }
}

static void do_single_path(const Graph *g)
{
    list_buildings(g);
    int src = read_node(g, "Start building id");
    int dst = read_node(g, "Destination id   ");

    printf("\n  -- Route: %s  ->  %s --\n",
           g->nodes[src].name, g->nodes[dst].name);

    Path p;
    if (astar(g, src, dst, &p))
        path_print(g, &p);
    else
        printf("  [!] No route found (all roads might be blocked).\n");
}

static void do_multi_path(const Graph *g)
{
    list_buildings(g);

    int waypoints[32];
    int wcount = 0;

    printf("  Enter waypoint ids one by one. Type -1 when done.\n");
    while (wcount < 31) {
        int id;
        printf("  Waypoint %d id (-1 to finish): ", wcount + 1);
        if (scanf("%d", &id) != 1) { clear_input(); continue; }
        clear_input();
        if (id == -1) break;
        if (id < 0 || id >= g->num_nodes) { printf("  Invalid id.\n"); continue; }
        waypoints[wcount++] = id;
    }

    if (wcount < 2) { printf("  Need at least 2 waypoints.\n"); return; }

    float grand_total = 0.f;

    printf("\n  == Multi-stop Route ==========================\n");
    for (int i = 0; i < wcount - 1; i++) {
        printf("\n  Leg %d : %s  ->  %s\n",