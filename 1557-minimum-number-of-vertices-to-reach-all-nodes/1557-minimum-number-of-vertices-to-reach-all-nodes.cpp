class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        unordered_map<int, int> hMap;
        vector<int> ans;

        for(auto edge : edges)
        {
            hMap[edge[1]]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(hMap[i] == 0)
                ans.push_back(i);
        }

        return ans;   
    }
};