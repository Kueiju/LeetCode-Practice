class Solution {
public:
    int maximumSum(vector<int>& nums) {

        unordered_map<int, int> hMap;
        int ans = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int temp = nums[i];

            while(temp)
            { 
                sum += temp % 10;
                temp /= 10; 
            }

            if(hMap.count(sum))
            {
                ans = max(ans, hMap[sum] + nums[i]);
                hMap[sum] = max(hMap[sum], nums[i]);
            }
            else
                hMap[sum] = nums[i];
        }
        
        return (ans == INT_MIN) ? -1 : ans;
    }
};