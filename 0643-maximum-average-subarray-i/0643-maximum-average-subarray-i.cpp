class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0.0;
        int maxval = 0.0;
        
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        
        maxval = sum;
        
        for(int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            
            maxval = max(maxval, sum);
        }
        
        return (double)maxval / k;
    }
};