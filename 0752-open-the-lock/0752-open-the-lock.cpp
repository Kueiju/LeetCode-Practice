class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;

        unordered_set<string> seen(deadends.begin(), deadends.end());

        queue<pair<string, int>> q;

        q.push({"0000", 0});

        while(!q.empty())
        {
            pair<string, int> top = q.front();
            q.pop();

            if(top.first == target)
                return top.second;

            for(string nr : neighbor(top.first))
            {
                if(!seen.contains(nr))
                {
                    seen.insert(nr);
                    q.push({nr, top.second + 1});
                }
            }
        }

        return -1;
    }

    vector<string> neighbor(string node)
    {
        vector<string> ans;
        for(int i = 0; i < 4; i++) // each digit
        {
            for(int x : {1, -1}) // num - 1, num + 1
            {
                int val = (node[i] - '0' + x + 10) % 10 + '0';
                string neighbor = node;
                neighbor[i] = val;
                ans.push_back(neighbor);
            }
        }

        return ans;
    }
};