class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        //sort(piles.begin(), piles.end());
        // int divMin = piles[0];
        // int divMax = piles[piles.size() - 1];
        // int totaltimeMin = 0;
        // int totaltimeMax = 0;
        // for(int i = 0; i < piles.size(); i++)
        // {
        //     totaltimeMin += (piles[i] + divMin - 1) / divMin;
        //     totaltimeMax += (piles[i] + divMax - 1) / divMax;
        // }
        
        int left = 1;
        int right = 0;

        for(auto pile : piles)
        {
            right = max(right, pile);
        }

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(check(mid, piles, h))
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return left;
    }

    bool check(int k, vector<int>& piles, int limit) 
    {
        long hours = 0;
        for (double bananas: piles) 
        {
            hours += ceil(bananas / k);
        }
        
        return hours <= limit;
    }
};

//time complexity: find max right O(n) + binary search (logk) as outer loop, but inner loop will take O(n) => total O(n) + O(nlogk)
//space complexity: O(1)