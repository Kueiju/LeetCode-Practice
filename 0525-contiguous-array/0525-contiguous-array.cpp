class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> hMap;
        
        int ans = 0;
        int curr = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            if(nums[i] == 0)
            {
                curr -= 1;
            }
            else
                curr += 1;
            
            if(curr == 0)
                ans = i + 1;
            else
            {
                if(hMap.find(curr) != hMap.end())
                    ans = max(ans, i - hMap[curr]);
                else
                    hMap[curr] = i;
            }
        }
        
        return ans;
    }
};