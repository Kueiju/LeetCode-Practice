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
         //ans[k] = sum;
        ans[k] = sum / (2*k + 1);
        
        for(int i = 2*k + 1; i < size; i++)
        {
            sum += nums[i] - nums[i - 2*k - 1];
            ans[i - k] = sum / (2*k + 1);
            //ans[i] = sum / (2*k + 1);
        }
        
        // for(int i = 0; i < size; i++)
        // {
        //     if(ans[i] != -1)
        //         ans[i] /= (2*k + 1);
        // }

        return ans;
    }
};