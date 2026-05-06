#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("  +====================================================+\n");
    printf("  |        UNIVERSITY CAMPUS NAVIGATION SYSTEM         |\n");
    printf("  |          A* Shortest Path  --  Phase 3             |\n");
    printf("  |        Greenfield University  |  PBL Project        |\n");
    printf("  +====================================================+\n\n");
}

static void list_buildings(const Graph *g)
{
    printf("\n  -------- Campus Buildings --------\n");
    for (int i = 0; i < g->num_nodes; i++)
        printf("  [%2d]  %s\n", i, g->nodes[i].name);
    printf("  ----------------------------------\n\n");
}

static void print_menu(void)
{
    printf("  +--------------------------------------------+\n");
    printf("  |              MAIN MENU                     |\n");
    printf("  |  1. Find Shortest Path (Single)            |\n");
    printf("  |  2. Multi-Stop Waypoint Route              |\n");
    printf("  |  3. Block a Road                           |\n");
    printf("  |  4. Unblock a Road                         |\n");
    printf("  |  5. View Campus Map & Road Status          |\n");
    printf("  |  6. List All Buildings                     |\n");
    printf("  |  0. Exit                                   |\n");
    printf("  +--------------------------------------------+\n");
    printf("  Enter choice: ");
}

static int read_int(const char *prompt, int min, int max)
{
    int val;
    while (1) {
        printf("  %s (%d-%d): ", prompt, min, max);
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            clear_input();
            return val;
        }
        printf("  [!] Invalid input. Try again.\n");
        clear_input();
    }
}

static void feature_single_path(Graph *g)
{
    printf("\n  --- Find Shortest Path ---\n");
    list_buildings(g);

    int src = read_int("Enter START building ID  ", 0, g->num_nodes - 1);
    int dst = read_int("Enter DESTINATION ID     ", 0, g->num_nodes - 1);

    if (src == dst) {
        printf("  [!] Start and destination are the same.\n\n");
        return;
    }

    printf("\n  Calculating path: %s  -->  %s ...\n",
           g->nodes[src].name, g->nodes[dst].name);

    Path p;
    if (astar(g, src, dst, &p))
        path_print(g, &p);
    else
        printf("\n  [!] No path found. All roads may be blocked.\n\n");
}

static void feature_multi_stop(Graph *g)
{
    printf("\n  --- Multi-Stop Waypoint Route ---\n");
    list_buildings(g);

    int num_stops = read_int("How many stops (2-6)?    ", 2, 6);

    int stops[6];
    for (int i = 0; i < num_stops; i++) {
        char prompt[48];
        if (i == 0)
            snprintf(prompt, sizeof(prompt), "Enter START building ID  ");
        else if (i == num_stops - 1)
            snprintf(prompt, sizeof(prompt), "Enter FINAL DESTINATION  ");
        else
            snprintf(prompt, sizeof(prompt), "Enter STOP %d building ID ", i + 1);

        stops[i] = read_int(prompt, 0, g->num_nodes - 1);
    }

    printf("\n  +====================================================+\n");
    printf("  |              MULTI-STOP ROUTE PLAN                 |\n");
    printf("  +====================================================+\n");

    float grand_total = 0.0f;
    int   all_found   = 1;

    for (int i = 0; i < num_stops - 1; i++) {
        printf("\n  >>> LEG %d: %s  -->  %s\n",
               i + 1,
               g->nodes[stops[i]].name,
               g->nodes[stops[i + 1]].name);

        Path p;
        if (astar(g, stops[i], stops[i + 1], &p)) {
            path_print(g, &p);
            grand_total += p.total_dist;
        } else {
            printf("  [!] No path found for this leg.\n\n");
            all_found = 0;
        }
    }

    printf("  +====================================================+\n");
    if (all_found)
        printf("  |  GRAND TOTAL DISTANCE: %-5.0f metres              |\n",
               grand_total);
    else
        printf("  |  GRAND TOTAL: INCOMPLETE (some legs blocked)       |\n");
    printf("  +====================================================+\n\n");
}

static void list_roads(const Graph *g)
{
    char seen[20][64];
    int  count = 0;

    printf("\n  -------- All Roads --------\n");
    for (int i = 0; i < g->num_nodes; i++) {
        for (Edge *e = g->adj[i]; e; e = e->next) {
            int already = 0;
            for (int k = 0; k < count; k++) {
                if (strcmp(seen[k], e->road_name) == 0) {
                    already = 1;
                    break;
                }
            }
            if (!already && count < 20) {
                strncpy(seen[count], e->road_name, 63);
                printf("  [%2d]  %-30s  %s\n",
                       count + 1,
                       e->road_name,
                       e->blocked ? "[BLOCKED]" : "[OPEN]");
                count++;
            }
        }
    }
    printf("  ---------------------------\n\n");
}

static void feature_block_road(Graph *g, int block)
{
    if (block)
        printf("\n  --- Block a Road ---\n");
    else
        printf("\n  --- Unblock a Road ---\n");

    list_roads(g);

    char roads[20][64];
    int  count = 0;

    for (int i = 0; i < g->num_nodes; i++) {
        for (Edge *e = g->adj[i]; e; e = e->next) {
            int already = 0;
            for (int k = 0; k < count; k++) {
                if (strcmp(roads[k], e->road_name) == 0) {
                    already = 1;
                    break;
                }
            }
            if (!already && count < 20)
                strncpy(roads[count++], e->road_name, 63);
        }
    }

    int choice = read_int("Enter road number", 1, count);
    graph_block_road(g, roads[choice - 1], block);

    if (block)
        printf("  [OK] Road \"%s\" is now BLOCKED.\n\n", roads[choice - 1]);
    else
        printf("  [OK] Road \"%s\" is now OPEN.\n\n", roads[choice - 1]);
}

int main(void)
{
    Graph *g = graph_create();
    campus_build(g);
    print_banner();

    int choice;
    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            clear_input();
            choice = -1;
        } else {
            clear_input();
        }

        switch (choice) {
            case 1: feature_single_path(g);    break;
            case 2: feature_multi_stop(g);     break;
            case 3: feature_block_road(g, 1);  break;
            case 4: feature_block_road(g, 0);  break;
            case 5: graph_print(g);            break;
            case 6: list_buildings(g);         break;
            case 0:
                printf("\n  Thank you for using Campus Navigation!\n");
                printf("  Goodbye!\n\n");
                break;
            default:
                printf("  [!] Invalid choice. Enter 0-6.\n\n");
                break;
        }
    } while (choice != 0);

    graph_destroy(g);
    return 0;
}