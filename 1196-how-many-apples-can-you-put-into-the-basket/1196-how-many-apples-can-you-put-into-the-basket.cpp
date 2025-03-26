class Solution {
public:
    int maxNumberOfApples(vector<int>& weight, int max = 5000) {
        
        sort(weight.begin(), weight.end(), [](const int& a, const int& b){ return a < b;});
        
        int ans = 0;
        for(auto& val : weight)
        {
            if(max >= val)
            {
                max -= val;
                ans++;
            }
            else
                break;
        }
        
        return ans;
        
    }
};

//time complexity: sort => O(nlogn) + iteration => O(n)
//space complexity: O(1) for ans, val variables, or consider in-place sorting space required O(logn)