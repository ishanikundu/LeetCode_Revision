Approach 1 : Space Detection

 string str = "";
string ans = "";
stack<string> st;
int i = 0;

// Iterate through the string to split words and push them onto the stack
while (i < s.size())
{
    if (s[i] != ' ')
    {
        str += s[i]; // Build the current word
    }
    else if (s[i] == ' ')
    {
        if (!str.empty())
        { // Push the word onto the stack when a space is encountered
            st.push(str);

            str=""; // Clear str to build the next word if not done then pervious word will still in str
        }
    }
    i++;
}

// Push the last word onto the stack
if (!str.empty())
{
    st.push(str);
}

// Pop words from the stack to reverse their order
while (!st.empty())
{
    ans += st.top(); // Add the word to the result
    st.pop();        // Remove the word from the stack
    if (!st.empty())
    {
        ans += " "; // Add a space between words
    }
}

return ans;
---------------------------------- -- -- -- -- -- -- -- -- -- -- --
Approach 2 : Two pointer 
https:leetcode.com/problems/reverse-words-in-a-string/solutions/4884894/best-explanation-with-photos-without-extra-space-beats-100-in-time-95-in-space/


 string reverseWords(string s) {
        // using two pointer Approach :
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;
        while(i < n){
            while(s[i] ==' ' && i<n) i++;
            if(i == n) break;
            while(i < n && s[i]!=' '){
                s[right] = s[i];
                i++;
                right++;
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right]=' ';
            right++;
            left = right;
            i++;
        }
        s.resize(right-1);
        return s;
 }