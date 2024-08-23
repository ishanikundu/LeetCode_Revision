SubArray sum which is Divisible by K

Approach 1 : BRUTE FORCE O(n ^ 2)
WE WILL USE TWO LOOP

int divisibleByK(vector<int> nums, int k)
{
  for(int i = 0; i < nums.size(); i++){
      sum = 0;
      for(int j = i; j < nums.size(); j++){
        sum += nums[j];
        if(sum % K==0){
          count++;
        }
    }
    return count;
  }
}
-----------------------------------

 Approach 2 :  HashMap O(n)
 // check whether the remainder present in map ?
// Also check if the remainder is negative then ??? remainder + k
// insert Remainder
  
 unordered<int, int>mp;
  for(int i = 0; i < nums.size(); i++){
      prefixSum+=nums[i];
      int remainder = prefixSum % k;
      if(remainder < 0) remainder += k;
      if(mp.find(remainder) != mp.end()) {
        count += mp[remainder];
      }
      mp[remainder]++;
  }

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Approach 3: Sliding Window

Sliding Window Will not be Applicable in this case as we are not sure whther while shrinking 
the window the prefixSum will be divisible by k or not

eg : [ 4, 5, 0, -2, -3, 1 ],k = 5 
                   right
         left
sum = 4+5=9     9-4 = 5   c=1,2
5+0-2 =3-3 0 

int left = 0;
int right = 0;
while(right<nums.size()){
        sum += nums[right];
      while(sum % k != 0 && left<=right){
            sum -=nums[left];
            left++;
        }
        if(sum == k) count++;

        right++;
    }
    return count;
