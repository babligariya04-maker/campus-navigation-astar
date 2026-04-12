CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -Iinclude
LIBS   = -lm

TARGET = campus_nav
SRCS   = src/main.c src/graph.c src/astar.c src/campus.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)