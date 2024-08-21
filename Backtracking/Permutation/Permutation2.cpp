dublicate numbers present in nums so you have to return all possible permutation

    eg = [112] all must be unique permutation

Using Set : 


vector<int> temp;
vector<vector<int>> ans;
set<vector<int>> st;
vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        backtrack(0, nums, temp, st);
        ans.assign(st.begin(), st.end());
        return ans;
    }
void backtrack(int start, vector<int> &nums, vector<int> &temp, set<vector<int>> &st)
    {
        if (temp.size() == nums.size())
        {
            st.insert(temp);
            return;
        }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        temp.push_back(nums[start]);
        backtrack(start + 1, nums, temp, st);
        temp.pop_back();
        swap(nums[start], nums[i]);
    }
}
