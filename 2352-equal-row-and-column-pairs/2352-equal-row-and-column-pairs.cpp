class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        map<vector<int>, int> hMapR;
        map<vector<int>, int> hMapC;
        
        //cout << "grid.size() = " << grid.size() << endl;
        
        for(vector<int>& vecR : grid)
        {
            hMapR[vecR]++;
        }
        
        for(int col = 0; col < grid[0].size(); col++)
        {
            vector<int> vecC;
            for(int row = 0; row < grid.size(); row++)
            {
                vecC.push_back(grid[row][col]);
            }
            
            hMapC[vecC]++;
        }
        
        int ans = 0;
        
        for(auto& [key, val] : hMapR)
        {
            ans += val * hMapC[key];
        }
        
        return ans;
    }
};