class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());

        vector<int> returnArr;
       
        for(double spell : spells)
        {
            int left = 0;
            int right = potions.size();
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(potions[mid] >= (success / spell)) //find the most left one if the find vector has duplicated elements
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }

            returnArr.push_back(potions.size() - left);
        }

        return returnArr;
    }
};

//time complexity: sort O(mlogm) + binary search (nlogm)
//space complexity: O(n)