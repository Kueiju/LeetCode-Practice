class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int totalPartitionNum = 1;

        sort(nums.begin(), nums.end()); // 1 2 3

        int smallVal = nums[0];
        for(auto val : nums)
        {
            if(val - smallVal <= k)
            {
                continue;
            }
            else
            {
                smallVal = val;
                totalPartitionNum++;
            }
        }
        
        return totalPartitionNum;
    }
};