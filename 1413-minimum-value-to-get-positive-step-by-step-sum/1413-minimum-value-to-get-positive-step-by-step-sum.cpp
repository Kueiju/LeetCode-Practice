class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int minval = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            minval = min(minval, sum);
        }
        
        return (minval <= 0) ? (abs(minval) + 1) : 1;
        
    }
};