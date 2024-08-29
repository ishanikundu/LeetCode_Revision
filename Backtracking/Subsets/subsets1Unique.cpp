// Given an integer array nums of unique elements, return all possible subsets
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> temp;
    set<vector<int>> st;
    backtrack(0, nums, temp, st);
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
void backtrack(int start, vector<int> &nums, vector<int> &temp, set<vector<int>> &st)
{
    st.insert(temp);
    for (int i = start; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrack(i + 1, nums, temp, st);
        temp.pop_back();
    }
}