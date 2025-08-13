class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        vector<int> prefix = {nums[0]};
        int minval = min(INT_MAX, nums[0]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(prefix.back() + nums[i]);
            minval = min(minval, prefix.back());
        }
        
        return (minval >= 0) ? 1 : abs(minval) + 1;
        
    }
};