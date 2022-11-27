# Compilation

Type the command `make all` in the root of the project to compile the game, make sure the machine has a recent version of `Make`.

# Running

Run the binary `Exam` with the command `./Exam` or run the command `make run` in the root of the project.

# Abstract data types used in source code

The source code relies on graphs for representing the connections between different places in the map, the graph is represented with a weighted adjacency list (the weights are the distances in pixels). Character movement is determined using Dijkstra's algorithm implemented with priority queue.
