# Divide and Conquer

##  O(logm + logn) k-th smallest element in the union of the two sorted lists
```cpp
int kthSmallest(int arr1[], int arr2[], int m, int n, int k) {
    if (k > m + n || k < 1) return -1;
    if (m > n) return kthSmallest(arr2, arr1, n, m, k);
    if (m == 0) return arr2[k - 1];
    if (k == 1) return min(arr1[0], arr2[0]);
    int i = min(m, k / 2), j = min(n, k / 2);
    if (arr1[i - 1] > arr2[j - 1]) return kthSmallest(arr1, arr2 + j, m, n - j, k - j);
    return kthSmallest(arr1 + i, arr2, m - i, n, k - i);
}
```

## 2 n-bit multiplication Pseudo code: Karatsuba Multiplication O(n^1.59)
```cpp
int multiply(int x, int y, int n) {
    if (n == 1) return x * y;
    int a = x / 2, b = x % 2, c = y / 2, d = y % 2;
    int ac = multiply(a, c, n / 2);
    int bd = multiply(b, d, n / 2);
    int ad_bc = multiply(a + b, c + d, n / 2) - ac - bd;
    return ac * (1 << n) + ad_bc * (1 << (n / 2)) + bd;
}

```
## Gauss Multiplication O(n^2)
```cpp
int multiply(int x, int y) {
    if (x == 0 || y == 0) return 0;
    if (x == 1) return y;
    if (y == 1) return x;
    if (x % 2 == 0) return multiply(x / 2, y) << 1;
    return multiply(x / 2, y) << 1 + y;
}
```

## Strassen's Matrix Multiplication 4x4 -1 based indexing O(n^2.81)
```cpp
void strassen(int a[4x4], int b[4x4], int c[4x4]) {
    int p = (a11 + a22) * (b11 + b22);
    int q = b11 * (a21 + a22);
    int r = a11 * (b12 - b22);
    int s = a22 * (b21 - b11);
    int t = b22 * (a11 + a12);
    int u = (a21 - a11) * (b11 + b12);
    int v = (b21 + b22) * (a12 - a22);

    c11 = p + s - t + v;
    c12 = r + t;
    c21 = q + s;
    c22 = p + r - q + u;
}
```

## Median/ kth smallest element in O(n) time
```cpp
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for j=l to r - 1
        if a[j] < pivot
            i++;
            swap(a[i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}
int median(int a[], int n) {
    int k = (n + 1) / 2;
    int l = 0, r = n - 1;
    while (l < r) {
        int p = partition(a, l, r);
        if (p == k) return a[p];
        if (p < k) l = p + 1;
        else r = p - 1;
    }
    return a[l];
}
```

## Closest Pair of Points O(nlogn)
```cpp
closestPair(x[], y[]){
    n = x.length;
    if (n == 2) return dist(x[1], y[2]);
    if (n == 3) return min(dist(x[1], y[2]), dist(x[2], y[3]), dist(x[3], y[1]));
    
    mid = x[n/2];
    dl = closestPair(x[1..mid], y);
    dr = closestPair(x[mid + 1..n], y);
    d = min(dl, dr);

    s = points in y whose x-coordinate is in [mid.x - d, mid.x + d];
    for i=1 to s.length
        for j=(1 to 7)
            d = min(d, dist(s[i], s[i + j]));
    
    return d;
}
```

## Convex Hull O(nlogn)
```cpp
convexHull(points[]){
    sort(points);
    hull = [];
    for i=1 to points.length
        while hull.length >= 2 and orientation(hull[hull.length - 2], hull[hull.length - 1], points[i]) != counter-clockwise
            hull.pop();
        hull.push(points[i]);
    return hull;
}
```

# Greedy Algorithms

## Huffman Coding O(nlogn)
```cpp
huffmanCoding(freq[]){
    n = freq.length;
    priorityQueue pq;
    for i=1 to n
        pq.push(new Node(freq[i]));
    
    while pq.size() > 1
        left = pq.pop();
        right = pq.pop();
        pq.push(new Node(left.freq + right.freq, left, right));
    
    return pq.pop();
}
```

## Job Sequencing with deadline O(n^2)
```cpp
jobSequencing(jobs[]){
    sort(jobs);
    int result[] = new int[jobs.length];
    boolean slot[] = new boolean[jobs.length];
    for i=1 to jobs.length
        for j=min(jobs.length, jobs[i].deadline) to 1
            if slot[j] == false
                result[j] = i;
                slot[j] = true;
                break;
    return result;
}
```

## Fractional Knapsack O(nlogn)
```cpp
fractionalKnapsack(items[], W){
    sort(items);
    double profit = 0;
    for i=1 to items.length
        if W == 0
            break;
        int a = min(W, items[i].weight);
        profit += a * items[i].value / items[i].weight;
        W -= a;
    return profit;
}
```

## Activity Selection Problem: Train Platform Problem & Interval Scheduling O(nlogn)
```cpp
activitySelection(activities[]){
    sort(activities);
    int count = 1;
    int end = activities[1].end;
    for i=2 to activities.length
        if activities[i].start >= end
            count++;
            end = activities[i].end;
    return count;
}
```

# Graph Algorithms

## DFS O(V+E)
```cpp
DFS(G, v){
    visited[v] = true
    For each neighbor u of v:
        If not visited[u]:
            DFS(G, u)
}
```

## BFS O(V+E)
```cpp
BFS(G, src){
    Initialize visited[] = false
    Initialize q
    q.push(src)
    visited[src] = true
    While q is not empty:
        u = q.pop()
        For each neighbor v of u:
            If not visited[v]:
                q.push(v)
                visited[v] = true
}
```

## Topological Sort O(V+E)
```cpp
DFS(G, v){
    visited[v] = true
    For each neighbor u of v:
        If not visited[u]:
            DFS(G, u)
    stack.push(v)
}
TopologicalSort(G){
    Initialize visited[] = false
    Initialize stack
    For each vertex v in G:
        If not visited[v]:
            DFS(G, v)
    Return stack
}
```

## Union-Find: Kruskal's MST algorithm O(ElogE)
```cpp
KruskalMST(G){
    Sort edges of G by weight
    Initialize MST = []
    Initialize parent[node] = node and rank[node] = 0 (Union-Find)
    For each edge (u, v) with weight w in sorted order:
        If Find(u) ≠ Find(v):  // No cycle
            Add (u, v, w) to MST
            Union(u, v)  // Merge sets
        If MST contains V-1 edges:
            Break
    Return MST
}
Find(x){
    If parent[x] = x:
        Return x
    Return Find(parent[x])  // Path compression
}
Union(x, y){ // Union by rank
    rootX = Find(x), rootY = Find(y)
    If rootX ≠ rootY:
        If rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        Else If rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        Else:
            parent[rootY] = rootX
            rank[rootX] += 1
}   

```

## Cycle Detection in both directed O(V+E) and undirected O(V)
```cpp
bool isCyclic(Graph G){
    For each vertex v in G:
        If not visited[v]:
            If isCyclicUtil(v, visited, -1):
                Return true
    Return false
}
bool isCyclicUtil(int v, bool visited[], int parent){
    visited[v] = true
    For each adjacent u of v:
        If not visited[u]:
            If isCyclicUtil(u, visited, v):
                Return true
        Else If u ≠ parent:
            Return true
    Return false
}
```

## Dijkstra's Algorithm: Weighted Shortest Path O(V^2)
```cpp
Dijkstra(G, src){
    Initialize dist[] = ∞, dist[src] = 0
    Initialize pq
    pq.push(src)
    While pq is not empty:
        u = pq.pop()
        For each neighbor v of u:
            If dist[v] > dist[u] + weight(u, v):
                dist[v] = dist[u] + weight(u, v)
                pq.push(v)
    Return dist
}
```

## Bellman-Ford Algorithm: Shortest Path with Negative Weights O(VE)
```cpp
BellmanFord(G, src){
    Initialize dist[] = ∞, dist[src] = 0
    For i=1 to V-1:
        For each edge (u, v) with weight w:
            If dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
    For each edge (u, v) with weight w:
        If dist[v] > dist[u] + w:
            Return false
    Return true
}
```

## Floyd-Warshall Algorithm: All Pairs Shortest Path O(V^3)
```cpp
FloydWarshall(G){
    Initialize dist[][]
    For i=1 to V:
        For j=1 to V:
            dist[i][j] = G[i][j]
    For k=1 to V:
        For i=1 to V:
            For j=1 to V:
                If dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    Return dist
}
```

## Singly Connected Components O(V+E)
```cpp
DFS(G, v){
    visited[v] = true
    For each neighbor u of v:
        If not visited[u]:
            DFS(G, u)
}
SCC(G){
    Initialize visited[] = false
    For each vertex v in G:
        If not visited[v]:
            DFS(G, v)
}
```

## Maximum flow: ford-fulkerson algorithm O(Ef)
```cpp
FordFulkerson(G, s, t){
    Initialize residualGraph = G
    Initialize parent[] = -1
    While BFS(residualGraph, s, t, parent):
        pathFlow = ∞
        For v=t, u=parent[v]:
            pathFlow = min(pathFlow, residualGraph[u][v])
        For v=t, u=parent[v]:
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow
    Return residualGraph
}
BFS(residualGraph, s, t, parent){
    Initialize visited[] = false
    Initialize q
    q.push(s)
    visited[s] = true
    While q is not empty:
        u = q.pop()
        For v=1 to V:
            If not visited[v] and residualGraph[u][v] > 0:
                q.push(v)
                parent[v] = u
                visited[v] = true
    Return visited[t]
}
```

## Bipartite Matching O(VE)
```cpp
bool isBipartiteMatching(G, src){
    Initialize color[] = -1
    color[src] = 1
    queue q
    q.push(src)
    While q is not empty:
        u = q.pop()
        For each neighbor v of u:
            If color[v] == -1:
                color[v] = 1 - color[u]
                q.push(v)
            Else If color[v] == color[u]:
                Return false
    Return true
}
```

# Dynamic Programming

## 01 Knapsack O(nW)
```cpp
Knapsack01(values, weights, n, W):
    DP[0..n][0..W] = 0
    For i = 1 to n:
        For w = 0 to W:
            If weights[i-1] ≤ w:
                DP[i][w] = max(DP[i-1][w], values[i-1] + DP[i-1][w - weights[i-1]])
            Else:
                DP[i][w] = DP[i-1][w]
    Return DP[n][W]
```

## Longest Common Subsequence O(nm)
```cpp
LCS(X, Y):
    m = len(X), n = len(Y)
    DP[0..m][0..n] = 0
    For i = 1 to m:
        For j = 1 to n:
            If X[i-1] == Y[j-1]:
                DP[i][j] = DP[i-1][j-1] + 1
            Else:
                DP[i][j] = max(DP[i-1][j], DP[i][j-1])
    Return DP[m][n]
```

## Longest Increasing Subsequence O(nlogn)
```cpp
LIS(A):
    n = len(A)
    DP[0..n-1] = 1
    For i = 1 to n-1:
        For j = 0 to i-1:
            If A[i] > A[j]:
                DP[i] = max(DP[i], DP[j] + 1)
    Return max(DP)
```

## Edit Distance - Levenshtein Distance O(nm)
```cpp
EditDistance(X, Y):
    m = len(X), n = len(Y)
    DP[0..m][0..n] = 0
    For i = 0 to m: DP[i][0] = i
    For j = 0 to n: DP[0][j] = j
    For i = 1 to m:
        For j = 1 to n:
            If X[i-1] == Y[j-1]:
                DP[i][j] = DP[i-1][j-1]
            Else:
                DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1], DP[i-1][j-1])
    Return DP[m][n]

```

## Matrix Chain Multiplication O(n^3)
```cpp
MatrixChainOrder(p, n):
    DP[1..n][1..n] = 0
    For l = 2 to n:  // Chain length
        For i = 1 to n-l+1:
            j = i + l - 1
            DP[i][j] = ∞
            For k = i to j-1:
                cost = DP[i][k] + DP[k+1][j] + p[i-1]*p[k]*p[j]
                DP[i][j] = min(DP[i][j], cost)
    Return DP[1][n]

```

## Travelling Salesman Problem O(2^n * n)
```cpp
TSP(G, n):
    DP[1..2^n][1..n] = ∞
    DP[1][1] = 0
    For mask = 1 to 2^n-1:
        For u = 1 to n:
            If (mask & (1 << (u-1))):
                For v = 1 to n:
                    If v ≠ u and (mask & (1 << (v-1))):
                        DP[mask][u] = min(DP[mask][u], DP[mask ^ (1 << (u-1))][v] + G[v][u])
    Return min(DP[2^n-1][u] + G[u][1] for u = 2 to n)
```

## Polynomial Solving O(n)
```cpp
int polynomialSolving(int coeff[], int n, int x){
    int ans = 0;
    for i=0 to n:
        ans += coeff[i] * pow(x, i);
    return ans;
}
```

## Multistage Graph O(E)
```cpp
MultistageGraph(G, stages):
    n = len(G)
    DP[1..n] = ∞
    DP[n] = 0
    For i = n-1 down to 1:
        For all (i, j) ∈ edges:
            DP[i] = min(DP[i], cost(i, j) + DP[j])
    Return DP[1]
```

## Optimal Binary Search Tree O(n^3)
```cpp
OBST(p, n):
    cost[1..n][1..n] = 0
    For length = 1 to n:
        For i = 1 to n-length+1:
            j = i + length - 1
            cost[i][j] = ∞
            For r = i to j:
                total = sum(p[i..j])
                cost[i][j] = min(cost[i][j], cost[i][r-1] + cost[r+1][j] + total)
    Return cost[1][n]
```

# Backtracking

## Graph Coloring O(m^n)
```cpp
GraphColoring(graph, m, n):
    colors[1..n] = 0  // Initialize all vertices with no color
    If Solve(1):
        Return colors
    Else:
        Return "No solution"

Solve(v):
    If v > n:
        Return true
    For c = 1 to m:
        If IsSafe(v, c):
            colors[v] = c
            If Solve(v + 1):
                Return true
            colors[v] = 0  // Backtrack
    Return false

IsSafe(v, c):
    For each neighbor u of v:
        If colors[u] == c:
            Return false
    Return true
```

## Sum of Subsets O(2^n)
```cpp
SumOfSubsets(S, n, T):
    solution[1..n] = 0  // Initialize all elements as excluded
    If Solve(1, 0, T):
        Return "Solution exists"
    Else:
        Return "No solution"

Solve(i, current_sum, T):
    If current_sum == T:
        Print(solution)  // Print the subset
        Return true
    If i > n or current_sum > T:
        Return false
    solution[i] = 1  // Include S[i]
    If Solve(i + 1, current_sum + S[i], T):
        Return true
    solution[i] = 0  // Exclude S[i]
    If Solve(i + 1, current_sum, T):
        Return true
    Return false
```

## N-Queen O(n!)
```cpp
NQueens(n):
    board[1..n][1..n] = 0  // Initialize empty board
    If Solve(1):
        Return board
    Else:
        Return "No solution"

Solve(row):
    If row > n:
        Return true
    For col = 1 to n:
        If IsSafe(row, col):
            board[row][col] = 1
            If Solve(row + 1):
                Return true
            board[row][col] = 0  // Backtrack
    Return false

IsSafe(row, col):
    For i = 1 to row-1:  // Check column
        If board[i][col] == 1:
            Return false
    For (i, j) = (row-1, col-1) to (1,1):  // Check upper-left diagonal
        If board[i][j] == 1:
            Return false
    For (i, j) = (row-1, col+1) to (1,n):  // Check upper-right diagonal
        If board[i][j] == 1:
            Return false
    Return true
```

# String Algorithms

## Naive String Matching O(nm)
```cpp
NaivePatternMatch(text, pattern):
    n = length(text)
    m = length(pattern)

    For i from 0 to n - m:
        If text[i...i+m-1] == pattern:
            Return "Pattern found at index i"
    Return "Pattern not found"
```

## Best case: O(n), worst case: O(nm) pattern matching
```cpp
NaivePatternMatch(text, pattern):
    s=0, count=0;
    while s<=n-m:
        for i=0 to m-1:
            if text[s+i] != pattern[i]:
                mismatch = true;
                s += i-1;
                break;
        if not mismatch:
            count++;
            return "Pattern found at index: " << s+1;
            s += m;
```

## Rabin-Karp Algorithm O(n + m -1), worst case O(nm)
```cpp
RabinKarp(text, pattern, d=256, q=101):
    n = length(text)
    m = length(pattern)
    h = d^(m-1) mod q   // Precompute hash factor
    p = 0               // Hash value for pattern
    t = 0               // Hash value for text window
    // Compute initial hash values
    For i from 0 to m-1:
        p = (d * p + pattern[i]) mod q
        t = (d * t + text[i]) mod q
    // Slide over text
    For s from 0 to n-m:
        If p == t:       // Hash match, verify characters
            If text[s...s+m-1] == pattern:
                Return "Pattern found at index s"
        If s < n-m:      // Update hash for next window
            t = (d * (t - text[s] * h) + text[s+m]) mod q
            If t < 0: t = t + q  // Ensure positive hash
    Return "Pattern not found"
```

# Approximation Algorithms

## Approximation Algorithm for Vertex Cover
```cpp
VertexCover(G):
    C = {}  // Initialize vertex cover set
    E' = E  // Set of uncovered edges

    While E' is not empty:
        Pick an arbitrary edge (u, v) ∈ E'
        Add u and v to C
        Remove all edges incident to u or v from E'

    Return C
```

## Approximation Algorithm for Set Cover
```cpp
SetCover(U, S):
    C = {}          // Initialize set cover
    Covered = {}    // Initialize covered elements

    While Covered ≠ U:
        Pick S_i ∈ S that covers the most uncovered elements
        Add S_i to C
        Add elements of S_i to Covered

    Return C
```

## Approximation Algorithm for Travelling Salesman Problem
```cpp
ApproxTSP(G):
    1. Compute MST of G (using Prim's or Kruskal's algorithm).
    2. Perform a preorder traversal of the MST starting from an arbitrary root vertex.
    3. Return the vertices visited in the traversal as the TSP tour.
```

## Bin Packing Problem
```cpp
BinPackingFFD(items, bin_capacity):
    1. Sort items in descending order of size.
    2. Initialize empty bins.
    3. For each item:
        a. Place the item into the first bin that has enough remaining capacity.
        b. If no bin can accommodate the item, open a new bin and place the item in it.
    4. Return the number of bins used.
```


# Randomized Algorithms
- Las Vegas Algorithm: Always gives correct result but time taken is random.
- Monte Carlo Algorithm: Always gives result in fixed time but result may be incorrect.

# P vs NP Problem
