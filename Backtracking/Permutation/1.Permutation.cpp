Permutation mean : 
Eg = nums = [1,2,3]
Possible Permutation : [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]  
'.' We can conclude in Permutation Arrangement matters 


vector<vector<int>>ans;
vector<int>temp;
vector<vector<int>>permutation(vector<int>nums){
    backtrack(0,nums,temp,start);
    return ans;
}
void backtrack(int start, vector<int>& nums,vector<int>& temp, vector<vector<int>>& ans){
    if(nums.size()==temp.size()){
       ans.push_back(temp);
       return;
    }
    for(int i = start; i < nums.size(); i++){
        swap(nums[start],nums[i]);
        temp.push_back(nums[start]);
        backtrack(start + 1,nums,temp,ans);
        temp.pop_back();
        swap(nums[start],nums[i]);

    }
}



Dry Run : 
1.
 i. backtrack(0,[1,2,3],[],[[]])
    start = 0
    i = 0
    swap(nums[i],nums[start])  -------> temp = [1]
 
 ii. backtrack(1,[1,2,3],[1],[[]])
      start = 1
      i = 1 
      swap(nums[i],nums[start]) ---------> temp[1,2]

 iii. backtrack(3,[1,2,3],[1,2],[[]])
      start = 3
      i = 3
      swap(nums[i],nums[start]) ----------> temp[1,2,3] 

iv. BASE CASE  :
     Now size == temp.size()
     '.' ans=[[1,2,3]]
     return backtrack(2,[1,2],[[1,2,3]])
     pop_back(3)
     swap([start],nums[i]) ----------> 
     now 
       i= 3  start = 2  "." swap(nums[i],nums[start]) --------------> NOW NEW  NUMS = [2,1,3]

2. 
i. nums = [2,1,3]
    start = 0
    i = 0
    so on..
    swap(nums[start],nums[i]) no change -----> temp[2]

ii. backtrack(1,[2,1,3],[2],[[1,2.3]])
   start = 1
   i = 1
   swap(nums[i],nums[start]) no change -----> temp[2,1]

iii.backtrack(2,[2,1,3],[2,1],[[1,2,3]])
    start = 2
    i = 2
    swap(nums[i],nums[start]) no change  -----> temp[2,1,3]

iv. size == temp.size() 
    ans = [[1,2,3],[2,1,3]]
   pop_back (3)
   start = 1
   i=1
   now i++
swap(nums[2],nums[1]) nums = [2,3,1]

   