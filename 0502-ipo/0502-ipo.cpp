class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        //make pairs for capital and profits

        vector<pair<int, int>> vec_pair;

        for(int i = 0; i < capital.size(); i++)
        {
            vec_pair.push_back({capital[i], profits[i]});
        }

        sort(vec_pair.begin(), vec_pair.end());

        int idx = 0;
        int num = capital.size();

        priority_queue<int> pq;

        for(int i = 0; i < k; i++)
        {
            while(idx < num && w >= vec_pair[idx].first)
            {
                pq.push(vec_pair[idx].second);
                idx++;
            }

            if(pq.empty())
            {
                return w;
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};