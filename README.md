# Campus Navigation System — A* Pathfinder

A command-line campus navigation system built in C
using the A* algorithm with an adjacency list graph.

---

## Project Phase Status

| Phase   | Status        | Description                                  |
|---------|---------------|----------------------------------------------|
| Phase 2 | Complete      | Core graph + A* shortest path working        |
| Phase 3 | Complete      | Road blocking, multi-stop routing, full menu |

---

## Features

- A* shortest path algorithm with Euclidean distance heuristic
- Adjacency list graph using linked lists
- Weighted edges — road distances in metres
- Road blocking and unblocking at runtime
- Multi-stop waypoint routing with grand total distance
- Full interactive menu system with 6 options
- Step-by-step directions with cumulative distance

---

## Campus Map — Greenfield University

12 buildings connected by 20 named roads:

| ID | Building        |
|----|-----------------|
|  0 | Main Gate       |
|  1 | Admin Block     |
|  2 | Lecture Hall A  |
|  3 | Lecture Hall B  |
|  4 | Library         |
|  5 | Canteen         |
|  6 | Hostel Block    |
|  7 | Sports Ground   |
|  8 | Lab Complex     |
|  9 | Medical Centre  |
| 10 | Auditorium      |
| 11 | Parking Lot     |

---

## Project Structure

campus-navigation-astar/
├── include/
│   ├── graph.h       # Graph, Node, Edge structs and API
│   ├── astar.h       # A* algorithm declarations
│   └── campus.h      # Campus map declaration
├── src/
│   ├── graph.c       # Adjacency list implementation
│   ├── astar.c       # A* engine with min-heap + path_print
│   ├── campus.c      # Greenfield University map data
│   └── main.c        # Phase 3 - full interactive menu
├── Makefile
└── README.md

---

## How to Build and Run

make
./campus_nav

## How to Clean

make clean

---

## Menu Options

  +--------------------------------------------+
  |              MAIN MENU                     |
  |  1. Find Shortest Path (Single)            |
  |  2. Multi-Stop Waypoint Route              |
  |  3. Block a Road                           |
  |  4. Unblock a Road                         |
  |  5. View Campus Map & Road Status          |
  |  6. List All Buildings                     |
  |  0. Exit                                   |
  +--------------------------------------------+

---

## Algorithm

- A* uses f(n) = g(n) + h(n)
- g(n) = actual road distance from start
- h(n) = Euclidean straight-line distance to goal
- Heuristic is admissible — path is always optimal
- Min-heap priority queue for fast node selection
- Blocked roads are skipped — A* auto-reroutes

---

## Author

University Campus Navigation System
Phase 3 — Problem Based Learning (PBL)
Built with C and A*