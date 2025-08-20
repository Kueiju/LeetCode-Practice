class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c : s)
        {
            if(c == '{' ||
               c == '(' ||
               c == '[')
               st.push(c);
            else
            {
                if(st.empty())
                    return false;
                {
                    if(st.top() == '}' ||
                       st.top() == ')' ||
                       st.top() == ']')
                       return false;
                    else
                    {
                        if(st.top() == '{')
                        {
                            if(c != '}')
                                return false;
                        }
                        else if(st.top() == '[')
                        {
                            if(c != ']')
                                return false;
                        }
                        else
                        {
                            if(c != ')')
                                return false;
                        }

                        st.pop();
                    }
                }
            }
        }
        return st.empty();
    }
};