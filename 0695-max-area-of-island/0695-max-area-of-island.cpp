class Solution {
public:

    vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> seen;

    int m;
    int n;

    vector<vector<int>> grid;

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        seen.assign(n, vector<bool>(m, false));

        this->grid = grid;

        int ans = 0;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(!seen[row][col])
                {
                    seen[row][col] = true;
                    if(grid[row][col] == 1)
                    {
                        ans = max(ans, dfs(row, col));
                    }
                }
            }
        }

        return ans;
    }

    int dfs(int ro, int co)
    {
        int area = 1;
        for(vector<int> direct : direction)
        {
            int nextrow = ro + direct[0];
            int nextcol = co + direct[1];
        
            if(valid(nextrow, nextcol) &&
               !seen[nextrow][nextcol])
            {        
                seen[nextrow][nextcol] = true;

                if(grid[nextrow][nextcol] == 1)
                {
                    area += dfs(nextrow, nextcol);
                }
            }
        }

        return area;
    }

    bool valid(int row, int col)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

};

// time complexity is O(m * n), since every grid will be visited once
// space complexity is O(m * n), which comes from seen