class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char, int> hMap;

        for(auto& jw : jewels)
        {
            hMap[jw]++;
        }

        int all = 0;

        for(auto& st : stones)
        {
            if(hMap.contains(st))
                all++;
        }
        
        return all;
    }
};