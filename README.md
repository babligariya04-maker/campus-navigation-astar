\# Campus Navigation System — A\* Pathfinder



A command-line campus navigation system built in C using the A\* algorithm with an adjacency list graph representation.



\## Features



\- A\* shortest path algorithm with Euclidean distance heuristic

\- Adjacency list graph using linked lists

\- Weighted edges (road distances in metres)

\- Road blocking and unblocking at runtime

\- Multi-stop waypoint routing with grand total distance

\- Step-by-step directions with cumulative distance



\## Campus Map — Greenfield University



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



\## Project Structure

campus-navigation-astar/

├── include/

│   ├── graph.h       # Graph, Node, Edge structs and API

│   ├── astar.h       # A\* algorithm declarations

│   └── campus.h      # Campus map declaration

├── src/

│   ├── graph.c       # Adjacency list implementation

│   ├── astar.c       # A\* engine with min-heap

│   ├── campus.c      # Greenfield University map data

│   └── main.c        # CLI interface

├── Makefile

└── README.md



\## How to Build



Make sure you have GCC installed. Then run:



```bash

make

```



\## How to Run



```bash

./campus\_nav

```



\## How to Clean



```bash

make clean

```



\## Algorithm



\- \*\*A\\\*\*\* uses a min-heap priority queue for the open set

\- \*\*Heuristic\*\* is straight-line Euclidean distance between node coordinates

\- The heuristic is admissible so the path found is always optimal

\- Blocked roads are skipped during traversal



\## Author



Greenfield University Navigation — built with C and A\*

