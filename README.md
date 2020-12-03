
                                                                   Hamiltonian Circuit using Backtracking
 For our test files will be assuming that all graphs are a 5x5. We will be having two Hamiltonian circuits and one that is not considered a Hamiltonian circuit. We will be showing how they are laid out in the text file, how each number is represented in the text file, and how each path looks in paper. When declaring vertices in graphs, each vertex will be either 1 or 0. The current vertices that are connected to the vertex we are dealing with will be 1 if not they will be zero. The vertex that we are currently declaring which vertices are connected or not will always be zero. For example, if we are declaring the vertices (2,3,4) that are connected to vertex “1” in the text file the “1” will be a zero and the vertices connected to vertex “1” will be one. The vertices that are not connected to vertex “1” will be zero.


Test File #1
0 1 1 1 0

1 0 0 1 1

1 0 0 1 0

1 1 1 0 1 

0 1 0 1 0

Hamiltonian Circuit Path: 0,1,4,3,2,0


Test File #2
0 1 0 1 0

1 0 1 1 1 

0 1 0 0 1

1 1 0 0 0

0 1 1 0 0

Hamiltonian Circuit does not exist!


Test File #3
0 1 0 1 0

1 0 0 0 1

0 0 0 1 1

1 0 1 0 1

0 1 1 1 0

Hamiltonian Circuit Path: 0,1,4,2,3,0

