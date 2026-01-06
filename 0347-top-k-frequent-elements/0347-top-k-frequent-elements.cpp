class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hMap;

        for(auto val : nums)
        {
            hMap[val]++;
        }

        priority_queue<pair<int, int>> maxpq;

        for(auto [key, val] : hMap)
        {
            maxpq.push({-val, key});
            if(maxpq.size() > k)
            {
                maxpq.pop();
            }
        }

        vector<int> ans;

        while(!maxpq.empty())
        {
            ans.push_back(maxpq.top().second);
            maxpq.pop();
        }

        return ans;
    }
};