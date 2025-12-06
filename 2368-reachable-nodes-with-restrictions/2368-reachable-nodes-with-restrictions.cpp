class Solution {
public:

    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    unordered_set<int> vec;

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        //this->vec = restricted;
        seen.assign(n, false);

        for(auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int ans = 1;

        seen[0] = true;
        
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());
        ans += dfs(0, restrictedSet);

        return ans;
    }

    int dfs(int node, unordered_set<int>& vec)
    {
        //unordered_set<int> restrictedSet(vec.begin(), vec.end());
        int ans = 0;
        for(auto neighbor : graph[node])
        {
            if(!seen[neighbor])
            {
                seen[neighbor] = true;
                //if(restrictedSet.find(neighbor) == restrictedSet.end())
                if(!vec.contains(neighbor))
                {
                    ans++;  
                    ans += dfs(neighbor, vec);    
                }
            }
        }

        return ans;
    }
};