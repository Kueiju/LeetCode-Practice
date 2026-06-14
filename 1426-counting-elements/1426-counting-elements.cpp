class Solution {
public:
    int countElements(vector<int>& arr) {
        
        unordered_map<int, int> hMap;
        int count = 0;
        
        for(auto elem : arr)
        {
            hMap[elem]++;
        }
        
        for(auto [elem, val] : hMap)
        {
            if(hMap.contains(elem + 1))
                count += hMap[elem];
        }
        
        return count;
    }
};