# 🏫 Campus Navigation System — A* Pathfinder

> A command-line campus navigation system built in **C** using the **A\* algorithm** with an adjacency list graph representation.

---

## 📊 Project Phase Status

| Phase | Status | Description |
|-------|--------|-------------|
| Phase 2 | ✅ Complete | Core graph + A* shortest path working |
| Phase 3 | ✅ Complete | Road blocking, multi-stop routing, full menu |

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🔍 A* Pathfinding | Shortest path using Euclidean heuristic |
| 🗺️ Campus Map | 12 buildings connected by 20 named roads |
| 🚧 Road Blocking | Block or unblock any road at runtime |
| 🛑 Auto Reroute | A* automatically finds alternate path |
| 📍 Multi-Stop Routing | Plan trips with up to 6 stops |
| 📏 Distance Tracking | Step-by-step directions with cumulative distance |
| 🖥️ Interactive Menu | Full CLI menu with 6 options |

---

## 🗺️ Campus Map — Greenfield University

12 buildings connected by 20 named roads:

| ID | Building | Coordinates |
|----|----------|-------------|
| 0 | 🚪 Main Gate | (0, 0) |
| 1 | 🏢 Admin Block | (20, 30) |
| 2 | 🎓 Lecture Hall A | (50, 40) |
| 3 | 🎓 Lecture Hall B | (80, 40) |
| 4 | 📚 Library | (50, 80) |
| 5 | 🍽️ Canteen | (20, 70) |
| 6 | 🏠 Hostel Block | (0, 100) |
| 7 | ⚽ Sports Ground | (90, 90) |
| 8 | 🔬 Lab Complex | (80, 10) |
| 9 | 🏥 Medical Centre | (10, 50) |
| 10 | 🎭 Auditorium | (50, 110) |
| 11 | 🅿️ Parking Lot | (90, 0) |

---

## 📁 Project Structure
campus-navigation-astar/
├── include/
│   ├── graph.h       # Graph, Node, Edge structs and API
│   ├── astar.h       # A* algorithm declarations + Path struct
│   └── campus.h      # Campus map function declaration
├── src/
│   ├── graph.c       # Adjacency list: create, add_edge, block_road, print
│   ├── astar.c       # A* engine with min-heap + path_print
│   ├── campus.c      # Greenfield University map data
│   └── main.c        # Phase 3 — full interactive menu
├── Makefile
└── README.md

---

## ⚙️ How to Build and Run

```bash
# Build
make

# Run
./campus_nav

# Clean
make clean
```

---

## 🖥️ Menu Options
+--------------------------------------------+
|              MAIN MENU                     |
|                                            |
|  1. Find Shortest Path (Single)            |
|  2. Multi-Stop Waypoint Route              |
|  3. Block a Road                           |
|  4. Unblock a Road                         |
|  5. View Campus Map & Road Status          |
|  6. List All Buildings                     |
|  0. Exit                                   |
+--------------------------------------------+

---

## 🧠 Algorithm
f(n) = g(n) + h(n)

| Symbol | Meaning |
|--------|---------|
| `f(n)` | Total estimated cost |
| `g(n)` | Actual road distance from start |
| `h(n)` | Euclidean straight-line distance to goal |

- ✅ Heuristic is **admissible** — path found is always **optimal**
- ✅ **Min-heap** priority queue for fast node selection
- ✅ Blocked roads are **skipped** — A* auto-reroutes instantly

---

## 📸 Sample Output
Finding path: Main Gate --> Library
Step 1: Take Central Avenue
-> Admin Block               (36 m)
Cumulative distance: 36 m
Step 2: Take Canteen Road
-> Canteen                   (40 m)
Cumulative distance: 76 m
Step 3: Take Green Path
-> Library                   (32 m)
Cumulative distance: 108 m
TOTAL DISTANCE: 108 metres
---

## 👩‍💻 Author

**University Campus Navigation System**
Phase 3 — Problem Based Learning (PBL)
Built with ❤️ in C using A* Algorithm