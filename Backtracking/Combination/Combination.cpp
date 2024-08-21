Combination is number of unique combination could be there where arrangments doesnot matter
eg  : n = [1,2,3] k=2
 Posiible combination : [1,2] [1,3],[3,2]

vector<vector<int>>combination(vector<int>nums,int k){
 backtrack(0,nums,k,temp,ans);
   return ans;
}
void backtrack(int start, vector<int>&nums, int k, vector<int>& temp, vector<vector<int>>& ans){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        temp.push_back(nums[i]);
        backtrack(i+1,nums,k,temp,ans);
        temp.pop_back();
    }
}