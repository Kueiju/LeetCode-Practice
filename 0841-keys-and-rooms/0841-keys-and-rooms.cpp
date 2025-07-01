class Solution {
public:

    unordered_set<int> set;
    vector<vector<int>> rooms;

    void dfs(int node)
    {
        for(auto val : rooms[node])
        {
            if(!set.contains(val))
            {
                set.insert(val);

                dfs(val);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;

        set.insert(0);

        dfs(0);

        return set.size() == rooms.size();
        
    }
};