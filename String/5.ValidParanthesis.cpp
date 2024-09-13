



stack<char> st;
for (int i = 0; i < s.size(); i++)
{
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
        st.push(s[i]);
    }
    else if (s[i] == '}')
    {
        // we are using !st.empty because 
        // suppose we have string only  str = "]"
        if (!st.empty() && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    else if (s[i] == ')')
    {
        if (!st.empty() && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    else if (s[i] == ']')
    {
        if (!st.empty() && st.top() == '[')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
}
return st.empty();