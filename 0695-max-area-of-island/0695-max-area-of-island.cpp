class Solution {
public:

    vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> seen;

    int m;
    int n;

    vector<vector<int>> grid;

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        this->m = grid[0].size();
        this->n = grid.size();
        this->grid = grid;

        seen = vector(grid.size(), vector<bool>(grid[0].size(), false));

        int ans = 0;

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(!seen[row][col] && grid[row][col] == 1)
                {
                    ans++;
                    seen[row][col] = true;
                    dfs(row, col);
                }
            }
        }

        return ans;
    }

    void dfs(int ro, int co)
    {
        for(vector<int> direct : direction)
        {
            int nextrow = ro + direct[0];
            int nextcol = co + direct[1];
        
            if(valid(nextrow, nextcol))
            {
                seen[nextrow][nextcol] = true;
                dfs(nextrow, nextcol);
            }
        }
    }

    bool valid(int row, int col)
    {
        return row >= 0 && row < n && col >= 0 && col < m && !seen[row][col] && grid[row][col] == 1;
    }

};