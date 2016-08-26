CC=gcc
SOURCES= a_to_tree.c main.c DFS_traversal.c BFS_traversal.c \
	properties.c tree_methods.c ../queues/queue_methods.c
DEPS= tree.h ../queues/queue.h

build: $(SOURCES) $(DEPS)
	$(CC) -g -o tree $(SOURCES) $(DEPS)

clean:
	rm -rf ./tree
