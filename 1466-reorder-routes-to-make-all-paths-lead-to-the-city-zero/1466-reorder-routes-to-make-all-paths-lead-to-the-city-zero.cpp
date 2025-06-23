class Solution {
public:
    unordered_map<int, vector<int>> hMap;
    set<pair<int, int>> roads;    
    vector<bool> seen;

    int minReorder(int n, vector<vector<int>>& connections) {

        seen = vector(n, false);
        for(auto connection : connections)
        {
            int x = connection[0];
            int y = connection[1];

            hMap[x].push_back(y);
            hMap[y].push_back(x);
            roads.insert({x, y});
        }
        
        seen[0] = true;

        return dfs(0);
    }

    int dfs(int node)
    {
        int ans = 0;
        for(auto edge : hMap[node])
        {
            if(!seen[edge])
            {
                if(roads.count({node, edge}))
                {
                    ans++;
                }

                seen[edge] = true;
                ans += dfs(edge);
            }
        }

        return ans;
    }
};