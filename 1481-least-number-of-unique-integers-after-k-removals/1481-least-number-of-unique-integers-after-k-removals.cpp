class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> hMap;

        for(int i = 0; i < arr.size(); i++)
        {
            hMap[arr[i]]++;  //O(nlogn)
        }

        priority_queue<pair<int, int>> pq;

        for(auto [key, val] : hMap)
        {
            pq.push({-val, key}); //O(n)
        }

        while(k > 0) //O(n)
        {
            if(pq.top().first * -1 > k)
                return pq.size(); 
            
            k -= pq.top().first * -1;

            if(k >= 0)
                pq.pop();
        }

        return pq.size();
        
    }
};