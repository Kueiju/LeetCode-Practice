class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int i = 0; 
        int j = people.size() - 1;
        int ans = 0;
        while(i <= j) //need to consider single element case (heaviest one), so i == j is considered
        {
            if(people[i] + people[j] <= limit)
            {
                i++;
            }

            j--;
            ans++;
        }

        return ans;
    }
};

//time complexity: sort (O(nlogn)) + two pointer (O(n)), sort dominated => O(nlogn)
//space complexity: from sort? O(logn)