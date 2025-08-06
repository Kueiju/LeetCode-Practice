class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int low = 0, high = nums.size() - 1;

        vector<int> ans (nums.size(), 0);
        
        int square = 0, idx = nums.size() - 1;

        while(low <= high)
        {
            if(abs(nums[low]) > abs(nums[high]))
            {
                square = nums[low];
                low++;               
            }
            else
            {
                square = nums[high];
                high--;
            }

            ans[idx] = pow(square, 2);
            idx--; 
        }
        
        return ans;
    }
};