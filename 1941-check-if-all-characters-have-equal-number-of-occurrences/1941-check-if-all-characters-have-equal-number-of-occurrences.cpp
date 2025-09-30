class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char, int> hMap;

        for(const auto& c : s)
        {
            hMap[c]++;
        }

        int sum = 0;
        for(const auto& pair : hMap)
        {
            if(sum == 0)
                sum = pair.second;
            else
            {
                if(sum != pair.second)
                    return false;
            }
        }
        
        return true;
    }
};