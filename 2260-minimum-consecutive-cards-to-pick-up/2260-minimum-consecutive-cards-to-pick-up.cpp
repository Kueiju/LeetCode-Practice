class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        unordered_map<int, int> hMap;

        int ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++)
        {
            auto it = hMap.find(cards[i]);
            if(it != hMap.end())
            {
                ans = min(ans, i - hMap[cards[i]] + 1);
            }
            hMap[cards[i]] = i;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};