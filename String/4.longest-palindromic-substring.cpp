
Approach : 1 brute Force

string longestPalindrome(string s)
{
    int maxLength = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string str = s.substr(i, j - i + 1);
            string rev = str;
            reverse(rev.begin(), rev.end());
            if (str == rev)
            {
                if (str.length() > maxLength)
                {
                    maxLength = str.length();
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}

--------------------------------------------------
Approach Two pointer

// i has been considered as middle 
// and then checking left == right

string longestPalindrome(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        string odd = expand(i, i, s);
        if (odd.size() > ans.size())
            ans = odd;
        string even = expand(i, i + 1, s);
        if (even.size() > ans.size())
            ans = even;
    }
    return ans;
}
string expand(int i, int j, string s)
{
    int left = i;
    int right = j;
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

----------------