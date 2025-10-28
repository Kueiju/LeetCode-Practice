class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hMap;
        vector<vector<string>> vec;

        for(auto& str : strs)
        {
            string t = str;
            sort(t.begin(), t.end());

            hMap[t].push_back(str);
        }

        for(auto& pair : hMap)
        {
            vec.push_back(pair.second);
        }
        
        return vec;
    }
};