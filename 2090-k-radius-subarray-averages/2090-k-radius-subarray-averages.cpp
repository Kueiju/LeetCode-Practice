class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)
            return nums;

        int size = nums.size();
        
        vector<int> ans (size, -1);
        
        if(size < 2*k + 1)
            return ans;
        
        long long sum = 0;
        
        for(int i = 0; i < 2*k + 1; i++)
        {
            sum += nums[i];
        }
        
        ans[k] = sum / (2*k + 1);
        
        for(int i = k + 1; i < size - k; i++)
        {
            sum += nums[i + k] - nums[i - k - 1];
            ans[i] = sum / (2*k + 1);
        }
        
        return ans;
    }
};