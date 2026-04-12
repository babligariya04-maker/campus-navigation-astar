#include <string.h>
#include "graph.h"
#include "campus.h"

void campus_build(Graph *g)
{
    g->num_nodes = 12;

    int id = 0;
#define NODE(name_, x_, y_) \
    do { g->nodes[id].id = id; \
         strncpy(g->nodes[id].name, name_, 63); \
         g->nodes[id].x = (x_); \
         g->nodes[id].y = (y_); \
         id++; } while(0)

    NODE("Main Gate",      0,   0);
    NODE("Admin Block",    20,  30);
    NODE("Lecture Hall A", 50,  40);
    NODE("Lecture Hall B", 80,  40);
    NODE("Library",        50,  80);
    NODE("Canteen",        20,  70);
    NODE("Hostel Block",   0,   100);
    NODE("Sports Ground",  90,  90);
    NODE("Lab Complex",    80,  10);
    NODE("Medical Centre", 10,  50);
    NODE("Auditorium",     50,  110);
    NODE("Parking Lot",    90,  0);
#undef NODE

    graph_add_edge(g,  0,  1,  36, "Central Avenue");
    graph_add_edge(g,  0,  8,  80, "East Drive");
    graph_add_edge(g,  0, 11,  90, "Perimeter Road");
    graph_add_edge(g,  1,  2,  36, "Scholar's Walk");
    graph_add_edge(g,  1,  9,  22, "Wellness Lane");
    graph_add_edge(g,  1,  5,  40, "Canteen Road");
    graph_add_edge(g,  2,  3,  30, "Faculty Row");
    graph_add_edge(g,  2,  4,  40, "Library Lane");
    graph_add_edge(g,  2,  8,  31, "Tech Boulevard");
    graph_add_edge(g,  3,  7,  54, "Sports Road");
    graph_add_edge(g,  3,  8,  30, "Lab Drive");
    graph_add_edge(g,  4,  5,  32, "Green Path");
    graph_add_edge(g,  4,  7,  40, "East Park Road");
    graph_add_edge(g,  4, 10,  30, "Auditorium Avenue");
    graph_add_edge(g,  5,  6,  30, "Hostel Lane");
    graph_add_edge(g,  5,  9,  22, "North Walk");
    graph_add_edge(g,  6, 10,  50, "Garden Road");
    graph_add_edge(g,  7, 10,  45, "Stadium Drive");
    graph_add_edge(g,  8, 11,  10, "Service Road");
    graph_add_edge(g,  9,  6,  51, "Hillside Path");
}