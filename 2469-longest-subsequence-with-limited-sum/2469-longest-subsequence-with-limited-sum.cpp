class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }

        vector<int> answer;

        for(auto query : queries)
        {
            int left = 0;
            int right = nums.size() - 1;
            int maxlen = 0;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(query >= nums[mid])
                {
                    left = mid + 1;
                }
                else //if(query < prefix[mid])
                {
                    right = mid - 1;
                }
            }
            answer.push_back(left);
        }

        return answer;
    }
};