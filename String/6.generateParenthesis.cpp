
Remember  close and open parenthesis you have to keep track
1. open parenthesis always < n    push  '('  in temp
2. close parenthesis always < open  push ')' in temp
3. After that base condition if temp.size == 2*n




Approach : Backtracking
vector<string> generateParenthesis(int n)
{
    int open_parenthesis;
    int close_parenthesis;
    string temp;
    vector<string> ans;
    parenthesis(0, 0, n, temp, ans);
    return ans;
}
void parenthesis(int open_parenthesis, int close_parenthesis, int n, string &temp, vector<string> &ans)
{
    if (temp.size() == 2 * n)
    {
        ans.push_back(temp);
        return;
    }
    if (open_parenthesis < n)
    {
        temp += '(';
        parenthesis(open_parenthesis + 1, close_parenthesis, n, temp, ans);
        temp.pop_back();
    }
    // closing must not exceed open bracket
    if (close_parenthesis < open_parenthesis)
    {
        temp += ')';
        parenthesis(open_parenthesis, close_parenthesis + 1, n, temp, ans);
        temp.pop_back();
    }
}