class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        vector<int> ans;

        unordered_map<int, int> hMap;

        for(auto vec : nums)
        {
            for(auto val : vec)
            {
                hMap[val]++;
            }
        }

        for(auto [key, val] : hMap)
        {
            if(val == nums.size())
            {
                ans.emplace_back(key);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};