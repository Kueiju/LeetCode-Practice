class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        if(cards.size() <= 1)
            return -1;

        unordered_map<int, int> hMap;

        int ans = -1;

        for(int i = 0; i < cards.size(); i++)
        {
            auto it = hMap.find(cards[i]);
            if(it == hMap.end())
            {
                hMap.emplace(cards[i], i);
            }
            else
            {
                ans = (ans == -1) ? max(ans, (i - hMap[cards[i]] + 1)) : min(ans, i - hMap[cards[i]] + 1);
                hMap[cards[i]] = i;
            }
        }
        
        return ans;
    }
};