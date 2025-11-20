class Solution {
public:

    string removechar(string& s, char cc)
    {
        string ss;
        for(char c : s)
        {
            if(!ss.empty() && c == cc)
            {
                ss.pop_back();
            }
            else
            {
                //if(ss.empty())
                {
                    if(c != cc)
                    {
                        ss.push_back(c);
                    }
                }
            }
        }

        return ss;
    }

    bool backspaceCompare(string s, string t) {

        string ans1;

        ans1 = removechar(s, '#');

        // for(char c : s)
        // {
        //     if(!ss.empty() && c == '#')
        //     {
        //         ss.pop_back();
        //     }
        //     else
        //     {
        //         if(ss.empty())
        //         {
        //             if(c != '#')
        //             {
        //                 ss.push_back(c);
        //             }
        //         }
        //     }
        // }

        string ans2;

        ans2 = removechar(t, '#');

        return ans1 == ans2;
    }
};