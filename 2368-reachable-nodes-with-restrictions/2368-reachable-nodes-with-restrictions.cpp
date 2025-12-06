class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<bool> seen(n, false);

        vector<vector<int>> neighbors(n);
        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            neighbors[nodeA].push_back(nodeB);
            neighbors[nodeB].push_back(nodeA);
        }

        for(auto res : restricted)
        {
            seen[res] = true;
        }

        queue<int> q;
        q.push(0);

        int ans = 0;
        seen[0] = true;

        while(!q.empty())
        {    
            int currNode = q.front();
            q.pop();
            ans++;

            for (auto nextNode : neighbors[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return ans;
    }
};