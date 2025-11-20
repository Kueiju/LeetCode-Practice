class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;
        string k;

        for(char c : s)
        {
            if(st.empty())
            {
                st.push(c);
            }
            else
            {
                if(st.top() == c)
                {
                    st.pop();
                }
                else
                    st.push(c);
            }
        }

        k.resize(st.size());

        auto it = k.rbegin();
        while(!st.empty())
        {
            *it = st.top();
            st.pop();
            it++;
        }

        return k;
    }
};