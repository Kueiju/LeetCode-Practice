class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> seen(n, false);
        int provinces = 0;
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                provinces++;
                seen[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !seen[j]) {
                            seen[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};

// Time Complexity Analysis
// Outer Loop (for i = 0 to n)
// Runs O(N) times, iterating over all nodes.
// BFS Traversal
// Each node is processed once (added to the queue and marked as seen).
// Each edge is checked once for connectivity.
// Since we're working with an adjacency matrix, checking isConnected[node][j] takes O(N) per node.
// Thus, in the worst case (a fully connected graph), BFS runs in O(N²).

// Space Complexity Analysis
// Seen Array (vector<bool> seen(n, false))
// Stores N elements → O(N).
// Queue (queue<int> q)
// In the worst case (one large connected component), the queue holds all nodes at some point → O(N).
// Adjacency Matrix (isConnected)
// Stored explicitly → O(N²).
// Thus, the total space complexity is O(N²) (dominated by the adjacency matrix).

// Final Complexity Summary
// Time Complexity: O(N²)

// Space Complexity: O(N²) (due to the adjacency matrix)