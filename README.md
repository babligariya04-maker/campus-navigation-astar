# Campus Navigation System — A* Pathfinder

A command-line campus navigation system built in C using the A* algorithm
with an adjacency list graph representation.

---

## Project Phase Status

| Phase | Status | Description |
|-------|--------|-------------|
| Phase 2 | ✅ Complete | Core graph + A* shortest path working |
| Phase 3 | 🔄 Planned | Advanced features (see roadmap below) |

---

## What Works Right Now (Phase 2)

- Build campus map as adjacency list graph
- 12 buildings and 20 named roads
- Weighted edges with real distances in metres
- A* algorithm with Euclidean heuristic
- Step-by-step directions with cumulative distance
- Single source to single destination pathfinding

---

## Phase 3 Roadmap (Coming Next)

These features are designed and planned but will be
implemented in Phase 3:

### 1. Road Blocking
- Mark any road as closed at runtime
- A* will automatically reroute around blocked roads
- Simulates construction or campus events

### 2. Multi-Stop Waypoint Routing
- Enter multiple destinations in one trip
- Example: Hostel → Canteen → Library → Lab
- Shows distance for each leg and grand total

### 3. Interactive Menu System
- Full CLI menu with all options
- Block/unblock roads interactively
- View full campus map and building list

---

## Campus Map

12 university buildings connected by 20 named roads:

| ID | Building        | Coordinates |
|----|-----------------|-------------|
|  0 | Main Gate       | (0, 0)      |
|  1 | Admin Block     | (20, 30)    |
|  2 | Lecture Hall A  | (50, 40)    |
|  3 | Lecture Hall B  | (80, 40)    |
|  4 | Library         | (50, 80)    |
|  5 | Canteen         | (20, 70)    |
|  6 | Hostel Block    | (0, 100)    |
|  7 | Sports Ground   | (90, 90)    |
|  8 | Lab Complex     | (80, 10)    |
|  9 | Medical Centre  | (10, 50)    |
| 10 | Auditorium      | (50, 110)   |
| 11 | Parking Lot     | (90, 0)     |

---

## Project Structure

campus-navigation-astar/
├── include/
│   ├── graph.h       # Graph, Node, Edge structs and API
│   ├── astar.h       # A* algorithm declarations
│   └── campus.h      # Campus map declaration
├── src/
│   ├── graph.c       # Adjacency list implementation
│   ├── astar.c       # A* engine with min-heap
│   ├── campus.c      # University campus map data
│   └── main.c        # Phase 2 - single path finder
├── Makefile
└── README.md

---

## How to Build and Run

```bash
make
./campus_nav
```

## How to Clean

```bash
make clean
```

---

## Algorithm

- A* uses f(n) = g(n) + h(n)
- g(n) = actual road distance from start
- h(n) = Euclidean straight-line distance to goal
- Heuristic is admissible — path is always optimal
- Min-heap priority queue for efficiency

---

## Author

University Campus Navigation System
Phase 2 — Problem Based Learning (PBL)