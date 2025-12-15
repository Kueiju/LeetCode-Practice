class Solution {
public:

    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestPath(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        queue<vector<int>> q;

        vector<vector<int>> seen (m, vector<int>(n, -1));

        // {row, col, remain, step}
        q.push({0, 0, k, 0});

        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();

            int nextrow = curr[0];
            int nextcol = curr[1];
            int remain = curr[2];
            int step = curr[3];

            if(nextrow == m - 1 && nextcol == n - 1)
                return step;

            if(grid[nextrow][nextcol] == 1)
            {
                if(remain == 0)
                    continue;
                else
                    remain--;
            }

            if(seen[nextrow][nextcol] >= remain)
            {
                continue;
            }

            seen[nextrow][nextcol] = remain;

            for(vector<int> direction : directions)
            {
                int row = nextrow + direction[0];
                int col = nextcol + direction[1];
                if(valid(row, col))
                {
                    q.push({row, col, remain, step + 1});
                }
            }
        }
        
        return -1;
    }

    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};