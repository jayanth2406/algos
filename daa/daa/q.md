# DAA Questions

## Lab Questions

1. Find kth smallest element in an array in linear time
2. Merge Sort
3. Implement Huffmann's algorithm
4. Implement the optimal algorithm to solve the Interval Scheduling Problem in C/C++.
5. Given a sorted array of distinct integers A[1, …….,n], you want to find out whether there is an index “i” for which A[i] = i. Implement a divide-and-conquer algorithm that runs in time O(log n).
6. You are given two sorted lists of size m and n. Implement an O(log m + log n) time algorithm for computing the k-th smallest element in the union of the two lists.
7. Implement an algorithm that checks if the given undirected graph is connected.
8. Check if there is any cycle in the given graph.
9. Identify the number of connected components in the given graph and, for each vertex, output the component number it belongs to.
10. Determine if the given graph is connected.
11. Produce a topological sort of the nodes whenever it is possible, otherwise, output it is not possible.
12. Find shortest path/distance to each vertex from the given source vertex assuming each edge weight is one.
13. Find shortest path/distance to each vertex from the given source vertex assuming each edge weight is positive.
14. Find shortest path/distance to each vertex from the given source vertex assuming each edge weight is any real number.
15. Identify the number of connected components in the given directed graph and, for each vertex, output the component number it belongs to.
16. Find the minimum spanning tree of a given connected, weighted undirected graph using the Union-Find data structure.
17. Find the longest increasing subsequence in a given sequence of numbers.
18. Calculate the edit distance between two strings. The edit distance represents the minimum number of edits -- insertions, deletions, or substitutions -- needed to transform one string into the other.
19. Input: Given n items, each with a specified weight and value, and a knapsack with a maximum weight capacity W.  
    - Output: Maximize the total value by selecting items such that their combined weight does not exceed W. Each item can be chosen an unlimited number of times.
20. Input: Given n items, each with a specified weight and value, and a knapsack with a maximum weight capacity W. 
    - Output: Maximize the total value by selecting items such that their combined weight does not exceed W. Each item can only be selected once.
21. Input: A sequence of n matrices, A-1, A-2, …., A_n, where the matrix  A_i has dimension m_{i-1} by m_i. 
    - Output: The minimum cost of multiplying the matrices. The cost of multiplying two matrices  A and B  is defined as the number of scalar multiplications required to compute AxB.

22. Implement Horner’s method to evaluate a polynomial P(x) at a given point x.
    - Given a polynomial of degree n: P(x) = a_n x^n + a_{n-1} x^{n-1} + ........ + a_1 x + a_0 and a specific value for x, your implementation should calculate P(x) using at most n multiplications and n additions.
    - Input: The polynomial coefficients  a_n, a_{n-1}, ...... , a_0  and the value x. The polynomial coefficients should be stored in an array coefficients, where coefficients[i] represents  a_{n-i}  (i.e., the coefficient of  x^{n-i}).
    - Output: The evaluated result of P(x).

23. Write a program to implement the naive string matching algorithm, which searches for occurrences of a given pattern string P within a text string T. Print the starting positions of each match found.
    - Input: A text T and a pattern P
    - Output: All starting indices in T where P matches.

24. Implement the Rabin-Karp algorithm to search for a pattern P within a text T.
    - Input: A text T, a pattern P, and a prime number q.
    - Output: Starting indices in T where P matches

## Topics

1. Introduction
    Characteristics of algorithms
    Asymptotic notation: big-oh, theta, big-omega, little-oh and little-omega, time complexity and space complexity
    Recurrence relations, ways to Solve Recurrence Relations: substitution, iterative, recurrence tree, master method
2. Divide and Conquer
    1. Merge Sort ****
    2. (Quick Sort****), Selection Sort
    3. Bitwise Addition & Multiplication of 2 n-bit numbers **
    4. Gauss Multiplication
    5. Matrix Multiplication of 2 nxn matrices
    6. Strassen's Matrix Multiplication ****
    7. Finding Median of 2 sorted arrays in O(log n) time **
    8. Finding kth smallest element in an array in O(n) time **
    9. Closest Pair of Points **
    10. Convex Hull **
    11. Karatsuba Multiplication **
    12. Binary Search
    13. GCD
3. Greedy Algorithms:
    1. Kruskal's Algorithm
    2. Prim's Algorithm
    3. Huffman Coding **
    4. Minimum cost spanning tree **
    5. Job Sequencing with deadline **
    6. Fractional Knapsack **
    7. Activity Selection Problem: Train Platform Problem & Interval Scheduling **
4. Graph Algorithms
    1. DFS ****
    2. BFS ****
    3. Topological Sort ****
    4. Connected Components
    5. Cycle Detection
    6. Strongly Connected Components
    7. Distance from a node to all other nodes
    8. Dijkstra's Algorithm: Weighted Shortest Path ****
    9. Bellman-Ford Algorithm: Shortest Path with Negative Weights
    10. Floyd-Warshall Algorithm: All Pairs Shortest Path
    11. Johnson's Algorithm: All Pairs Shortest Path with Negative Weights
    12. Minimum Spanning Tree
    13. Union-Find Data Structure
    14. Kruskal's Algorithm
    15. Prim's Algorithm
    16. Shortest Path in Weighted Directed Acyclic Graph
    17. Longest Path in Weighted Directed Acyclic Graph
    18. Maximum flow, Max flow min cut theorem, augmenting path
5. Dynamic Programming
    1. Fibonacci Series for very large n using both recursive and iterative methods
    2. Longest Common Subsequence
    3. Longest Increasing Subsequence
    4. Edit Distance - Levenshtein Distance: Minimum number of insertion, deleton & replacement operations required to convert one string into another
    5. Knapsack Problem: 0/1 Knapsack, Fractional Knapsack
    6. Matrix Chain Multiplication
    7. Shortest distance using all nodes exactly once in a weighted graph (Travelling Salesman Problem)
    8. Polynomial Solving
6. String Algorithms
    1. Naive String Matching
    2. Rabin-Karp Algorithm
    3. The Knuth- Morris-Pratt algorithm
7. Backtracking
    1. Graph coloring
    2. sum of subsets
    3. N-Queen Problem
8. P vs NP Problem
    Amortized Analysis
    Classes P and NP,
    reduction,
    NP-completeness,
    examples of NP-complete problems,
    Approximation algorithms,
    Randomized algorithms
