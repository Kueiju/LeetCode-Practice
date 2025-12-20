class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq (nums.begin(), nums.end());

        double sum = 0;
        for(auto val : nums)
        {
            sum += val;
        }
        
        sum /= 2.0;

        int ans = 0;

        if(pq.size() == 1)
            return 1;

        while(!pq.empty())
        {
            double val = pq.top();
            pq.pop();

            val /= 2.0;
            ans++;

            sum -= val;

            if(sum <= 0.0)
            {
                return ans;
            }

            pq.push(val);
        }

        return ans;

    }
};