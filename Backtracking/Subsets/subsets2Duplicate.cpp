
// Given an integer array nums that may contain duplicates, return all possible 
// subsets The solution set must not contain duplicate subsets. Return the solution in any order.


vector<int> temp;
set<vector<int>> st;
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
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