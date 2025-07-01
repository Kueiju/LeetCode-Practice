class Solution {
public:
    unordered_set<int> seen;
    vector<vector<int>> rooms;

    void dfs(int node)
    {
        for(auto& val : rooms[node])
        {
            if(seen.find(val) == seen.end())
            {
                seen.insert(val);
                dfs(val);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> rooms) {
        this->rooms = rooms;
        seen.insert(0);
        dfs(0);

        return seen.size() == rooms.size();
        
    }
};