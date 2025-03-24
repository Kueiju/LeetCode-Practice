class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> vec;
        
        int ans = num;
        while(num)
        {
            vec.push_back(num % 10);
            //cout << vec.back() << endl;
            num /= 10;
        }
        
        int idx = 0;
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

        //reverse(vec.begin(), vec.end());
        
        // for(int i = vec.size() - 1; i >= 0; i--)
        // {
        //     ans += vec[i] * pow(10, i);
        // }

        // for(int i = 0; i < vec.size(); i++)
        // {
        //     ans = ans * 10 + vec[i];
        // }
        
        return ans;
    }
};