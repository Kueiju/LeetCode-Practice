class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> hMap;

        for(int i = 0; i < arr.size(); i++)
        {
            hMap[arr[i]]++;  //O(n)
        }

        vector<int> vec;

        for(auto [element, frequency] : hMap)
        {
            vec.push_back(frequency); //O(n)
        }

        sort(vec.begin(), vec.end()); //qsort O(nlogn)

        // int idx = 0;
        // while (k > 0 && idx < vec.size()) {
        //     if (k >= vec[idx].first) {
        //         k -= vec[idx].first;
        //         idx++;
        //     } else {
        //         break;
        //     }
        // }

        // return vec.size() - idx;

        int ans = vec.size();

        for(int i = 0; i < vec.size(); i++) //possible iterate all the elements, so O(n)
        {           
            if(k >= vec[i])
            {
                k -= vec[i];
                ans--;
            }
            else
                break;
        }

        return ans;
    }
};