class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());
        //cout << potions[0] << endl;

        vector<int> returnVec;
        
        for(auto val : spells)
        {
            int left = 0;
            int right = potions.size() - 1;

            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(potions[mid] >= (success + val - 1) / val)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            returnVec.push_back(potions.size() - left);
        }
        
        return returnVec;
    }
};

//time complexity => sort: O(mlogm) + binary search: O(nlogm)
//space complexity => O(n)