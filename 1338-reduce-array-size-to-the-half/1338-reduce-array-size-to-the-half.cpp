class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> hMap;
        
        for(auto val : arr)
        {
            hMap[val]++; //O(n)
        }
        
        int halfOrigArrSize = arr.size() / 2;
        int n = arr.size();
        
        priority_queue<int> pq;
        
        for(auto [key, freq] : hMap)
        {
            pq.push(freq); //O(mlogm)
        }
        
        int ans = 0;
        while(!pq.empty()) //O(n)
        {
            int mostFreq = pq.top();
            n -= mostFreq;
            if( n <= halfOrigArrSize)
            {
                ans++;
                return ans; 
            }
            
            pq.pop();
            ans++;
            
        }
        
        return ans;
    }
};

//time complexity: O(mlogm), max heap dominated, each push costs O(logm), m <= n, n: array size
//space complexity: O(n), unordered_map requires space and dominated, O(m), max heap requires space