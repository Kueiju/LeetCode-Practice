class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> vec;
        
        int ans = num;
        while(num)
        {
            vec.push_back(num % 10);
            num /= 10;
        }
        
        int i = vec.size() - 1;
        for(i; i >= 0; i--)
        {
            if(vec[i] != 9)
            {
                vec[i] = 9;
                break;
            }
        }

        ans += 3 * pow(10, i);
        
        return ans;
    }
};