// it states the a target is given to you you have to find [i,j] index whose sum == target 
                  ie, nums[i] + nums[j] = target;

BRUTE Force :

 eg = target = 6, nums = [3,4,2]                                                                           
                          i       
                             j
vector<int> twoSum(int target, vector<int>nums){
     
     vector<int>ans
       for(int i = 0; i < nums.size(); i++){
          
          for(int j = i+1; j < nums.size(); j++){
              
              if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
              }
            }
       }  
       return ans;        
}

time Complexcity = O(n)* O(n) = n^2;
space Complexcity = 0(1);
---------------------------------------------------------------------------------------------------''
eg =[3,0,2,4]
      target = 6
    mp <element,index>
<mp[3] = 0>
<mp[0] = 1>
<mp[2] = 2>
<mp[4] = 3>

taking space : O(n) 
now find (target - nums[i]) is in map?
            6 - 3 = 3 ? No it is used once right ! to find the diff ** so mp[target-nums] != i  
            6 - 0 = 6? NO
            6 - 2 = 4 ? yes in index 3
            "."  print ith index and mp[4] th index 
vector<int> twoSum(int target, vector<int>nums){
       
       unordered_map<int,int>mp;
       for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
       }
       for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
        if(mp.find(diff)  !=  mp.end  &&  mp[diff] != i){
            return {i,mp[diff]};
        }
       }
       return {};
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
   One pass ie instead of forming map in seperate loop we will form map in one pass as we are traversing
              eg = [ 3, 0, 2, 4 ]
vector<int>twoSum(int target, vector<int> nums)
 {
       unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[diff] != mp.find)
        {
            return {i, mp[diff]};
        }
        // form the map
        mp[nums[i]] = i;
    }
    return {};
 }