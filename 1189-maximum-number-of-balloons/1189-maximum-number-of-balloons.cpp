class Solution {
public:
    int maxNumberOfBalloons(string text) {

        if(!text.contains('b') ||
           !text.contains('a') ||
           !text.contains('l') ||
           !text.contains('o') ||
           !text.contains('n'))
            return 0;

        unordered_map<char, int> hMap;

        for(auto& c : text)
        {
            switch(c)
            {
                case 'b':
                case 'a':
                case 'l':
                case 'o':
                case 'n':
                    hMap[c]++;
                    break;
                
                default:
                    break;
            }
        }

        int minval = INT_MAX;

        for(auto& pair : hMap)
        {
            

            if(pair.first == 'o' ||
                pair.first == 'l')
                pair.second /= 2;

            if(pair.second < INT_MAX)
            {
                minval = pair.second;
            }
        }

        return minval;
    }
};