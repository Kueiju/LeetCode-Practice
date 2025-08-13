class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        vector<long long> prefix = {nums[0]};

        for(int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(prefix.back() + nums[i]);
        }

        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(prefix[i] >= (prefix.back() - prefix[i]))
            {
                //cout << "prefix[" << i << "] = " << prefix[i] << endl;
                //cout << "subtract = " << prefix.back() - prefix[i] << ", prefix.back() = " << prefix.back() << endl;
                ans++;
            }
        }
        
        return ans;
    }
};