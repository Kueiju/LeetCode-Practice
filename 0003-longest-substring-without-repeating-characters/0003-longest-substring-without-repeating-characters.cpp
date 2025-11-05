class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        
        unordered_map<char, int> hMap;

        for(int right = 0; right < s.size(); right++)
        {
            if(hMap.find(s[right]) != hMap.end() && hMap[s[right]] >= left)
            {
               left = hMap[s[right]] + 1;
            }
            
            ans = max(ans, right - left + 1);
            
            hMap[s[right]] = right;

        }
        
        return ans;
    }
};