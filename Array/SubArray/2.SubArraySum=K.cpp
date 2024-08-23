We have to determine all possible subarray which equal to sum

1st Approach : Brute force


int subarraySum(vector<int> nums, int target)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[i];
            if (sum == target)
            {
                count++;
            }
        }
    }
    return count;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
2nd approach : hashMap
hint :  1. form a HashMap store(prefixSum, frequency) 
        2. Itterate : through the array, and find PreFixSum
        3. diff = prefixSum - target
        4. check whether diff there in map? why
           = > prefixSum + nums[i] = target 
           = > target - prefixSum = nums[i] 
        5. insert mp[prefixSum]++;

int subarraySum(vector<int> nums, int target)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int prefixSum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int diff = prefixSum - target if (mp.find(diff) != mp.end())
        {
            count += mp[diff];
            -- > not count++ we have to increment count in correspondence with diff
        }
        mp[prefixSum]++;
    }
    return count;
}

 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
Aproach 3 : inefficient    
Slidding Window 

int subarraySum(vector<int> nums, int target)
{
    int left = 0, right = 0;
    int prefixSum = 0;
    int count = 0;
    while (right < nums.size())
    {
        prefixSum += nums[right];
        while (prefixSum > target && left <= right)
        {
            prefixSum -= nums[left;] left++;
        }
        if (prefixSum == target)
            count++;
        right++;
    }
    return count;
}
