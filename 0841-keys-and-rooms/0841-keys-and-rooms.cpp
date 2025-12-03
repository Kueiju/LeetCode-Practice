class Solution {
public:

    vector<bool> seen;
    vector<vector<int>> rooms;
    unordered_set<int> set;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        seen = vector(rooms.size(), false);
        
        this->rooms = rooms;

        seen[0] = true;
        set.insert(0);
        dfs(0);

        for(int i = 0; i < rooms.size(); i++)
        {
            if(set.find(i) == set.end())
                return false;
        }

        return true;
    }
    
    void dfs(int node)
    {
        for(int neighbor : rooms[node])
        {
            if(!seen[neighbor])
            {
                seen[neighbor] = true;
                set.insert(neighbor);
                dfs(neighbor);
            }
        }
    }
};