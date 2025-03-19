class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        //make pairs for capital and profits
        vector<pair<int, int>> vec_pair;

        for(int i = 0; i < capital.size(); i++)
        {
            vec_pair.push_back({capital[i], profits[i]});
        }

        //sort vec_pair by their first, which is capital
        sort(vec_pair.begin(), vec_pair.end());

        int idx = 0;
        int num = capital.size();

        priority_queue<int> pq; //use heap to store the profits, and get the max profits

        while(k)
        {
            //compare and check how many elements are smaller or equal to the current w,
            //and push their profits into heap
            while(idx < num && w >= vec_pair[idx].first)
            {
                pq.push(vec_pair[idx].second);
                idx++;
            }

            //if no satisfied condition, return w
            if(pq.empty())
            {
                return w;
            }

            //get the maximum profit from the heap, and add it into w
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};