The same number may be chosen from candidates an unlimited number of times.Two combinations are unique if the
frequency of at least one of the chosen numbers is different.

eg = [ 2, 3, 6, 7 ]

i.backtrack(0, [ 2, 3, 6, 7 ], 7 - 2, [2], [[]])
ii.backtrack(0, [ 2, 3, 6, 7 ], 5 - 2, [ 2, 2 ], [[]])
iii.backtrack(0, [ 2, 3, 6, 7 ], 3 - 2, [ 2, 2, 2 ], [[]])
iv.backtrack(0, [ 2, 3, 6, 7 ], 1 - 2, [ 2, 2, 2, 2 ], [[]])
hits the base case:target < 0 
returns iii
pop_back(2)
as i gets incremented i = 1 
backtrack(1, [ 2, 3, 6, 7 ], 3 - 3, [ 2, 2, 3 ], [[ 2, 2, 3 ]]) as it reaches target == 0
------------------------------------------------------



vector<int> temp;
vector<vector<int>> ans;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
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
    // if target  negative
    if (target < 0)
    {
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        backtrack(i, candidates, target - candidates[i], temp, ans);
        temp.pop_back();
    }
}