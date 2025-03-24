class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        priority_queue<pair<int, int>> pq;
        
        vector<int> vect;
        for(auto& vec : boxTypes)
        {
            pq.push({vec[1], vec[0]});
            //cout << "vec[0] = " << vec[0] << endl; 
            //cout << "vec[1] = " << vec[1] << endl; 
        }
        
        int maxSum = 0;
        ///*
        while(!pq.empty())
        {
            int boxCount = min(truckSize, pq.top().second);
            maxSum += boxCount * pq.top().first;
            truckSize -= boxCount;
            pq.pop();

            if(truckSize == 0)
                break;
            
            /*
            if(truckSize - pq.top().second >= 0)
            {
                truckSize -= pq.top().second;
                cout << truckSize << endl;
                maxSum += pq.top().first * pq.top().second;
                cout << maxSum << endl;
                pq.pop();
            }
            else
                return maxSum;
                */
        }
        //*/
        
        return maxSum;
        
    }
};