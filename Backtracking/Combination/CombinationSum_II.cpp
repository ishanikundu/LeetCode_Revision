class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, temp, ans);
        return ans;
    }
    void backtrack(int start, vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
};