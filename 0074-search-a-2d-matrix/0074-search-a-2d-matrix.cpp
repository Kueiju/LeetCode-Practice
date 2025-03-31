class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix[0].size();
        int m = matrix.size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int col = mid % n;
            int row = mid / n;

            if(matrix[row][col] == target)
            {
                return true;
            }
            
            if(matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
        
    }
};

//time complexity: O(logn)
//space complexity: O(1)