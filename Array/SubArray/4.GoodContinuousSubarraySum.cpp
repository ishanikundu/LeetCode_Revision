A good subarray is a subarray where:

  1. its length is at least two, and
  2. the sum of the elements of the subarray is a multiple of k.
  REMEMBER : at least 2 will be the size meaning  size() == 2 or size() > 2 


Approach 1: Brute Force gives TLE

bool checkSubarraySum(vector<int> &nums, int k)

    int sum, len;
    // kth multiple && length has to be 2
    for (int i = 0; i < nums.size(); i++){
        sum = 0;
        len = 0;
        for (int j = i; j < nums.size(); j++){
            sum += nums[j];
            len++;
            if (len >= 2 && sum % k == 0){
                return true;
            }
        }
    }
return false;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Using HashMap we have to store   <remainder,indx>
why index is required??
   since we have to check length of the subarray must be ==2 or greater than 2
   eg : [2,4,3]  k=6
                               mp{0,-1}
      i=0   sum=2    2%6=2     mp{2,0}  
      i=1   sum=2+4   6%6=0     mp{0,1}  it is in map   1 - (-1) = 2 > 1    
                                             formula :   i - mp[0] 
                                                         = 1 - (-1)



 
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;          
        // As we have to store<remainder, index>; so we are assigning mp[0]=-1
        mp[0] = -1;
        since int sum = 0, remainder = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0)
                remainder += k;
            if (mp.find(remainder) != mp.end())
            {
                if (i - mp[remainder] > 1)
                {
                    // i - (whichever index it is found) > 1
                  return true;
                }
            }
            else
            {
                mp[remainder] = i;
            }
        }
        return false;
    }
};