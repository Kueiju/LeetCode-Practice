class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());
        //cout << potions[0] << endl;

        vector<int> returnVec;
        
        for(auto val : spells)
        {
            int sum = 0;
            int left = 0;
            int right = potions.size() - 1;

            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                //long long retval = val * potions[mid];
                if(potions[mid] >= (success + val - 1) / val)
                {
                    sum += right - mid + 1;
                    //cout << "right = " << right << endl;
                    //cout << "mid = " << mid << endl;
                    //cout << "sum = " << sum << endl;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                    //cout << "left = " << left << endl;
                }
            }

            returnVec.push_back(sum);
        }
        
        return returnVec;
    }
};