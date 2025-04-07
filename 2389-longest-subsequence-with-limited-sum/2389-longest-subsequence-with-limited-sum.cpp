class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        vector<int> preNum {nums[0]};

        //cout << preNum[0] << endl;
        for(int i = 1; i < nums.size(); i++)
        {
            preNum.push_back(preNum.back() + nums[i]);
            
        }
        vector<int> returnArr;

        for(auto query : queries)
        {
            int left = 0;
            int right = preNum.size() - 1;
            int maxlen = 0;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(query < preNum[mid])
                    right = mid - 1;
                else
                {
                    maxlen = mid + 1;
                    left = mid + 1;
                }
            }
            returnArr.push_back(maxlen);
        }
        return returnArr;
    }
};

//time complexity: sort: O(nlogn) + loop O(n^2)
//space complexity: O(n)