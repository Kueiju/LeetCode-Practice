class Solution {
public:
    
    unordered_map<int, vector<int>> graph;
    
    vector<bool> seen;
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        seen.assign(n, false);
        
        for(auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        //seen[0] = true;
        
        unordered_set<int> set (restricted.begin(), restricted.end());
        
        return dfs(0, set);
    }
    
    int dfs(int node, unordered_set<int>& set)
    {
        seen[node] = true;
        
        int ans = 1;
        
        for(int neighbor : graph[node])
        {
            if(!seen[neighbor] && !set.contains(neighbor))
            {
                ans += dfs(neighbor, set);
            }
        }
        
        return ans;
    }
    
    
};