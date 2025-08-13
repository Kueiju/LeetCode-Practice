class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long total = {nums[0]};

        for(int i = 1; i < nums.size(); i++)
        {
            total += nums[i];
        }

        int ans = 0;
        long left = 0, right = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            left += nums[i];
            right = total - left;

            if(left >= right)
                ans++;
        }
        
        return ans;
     }
};