class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        vector<int> ans;
        unordered_map<int, int> hMap;

        for(auto vec : nums)
        {
            for(auto item : vec)
            {
                hMap[item]++;
            }
        }

        for(const auto& pair : hMap)
        {
            if(pair.second == nums.size())
                ans.push_back(pair.first);
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};