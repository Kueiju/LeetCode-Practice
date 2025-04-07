class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        vector<int> prefix;

        prefix.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(prefix.back() + nums[i]);
        }

        vector<int> answer;

        for(auto query : queries)
        {
            int left = 0;
            int right = prefix.size() - 1;
            int maxlen = 0;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(query >= prefix[mid])
                {
                    maxlen = mid + 1;
                    left = mid + 1;
                }
                else //if(query < prefix[mid])
                {
                    right = mid - 1;
                }
            }
            answer.push_back(maxlen);
        }

        return answer;
        
    }
};