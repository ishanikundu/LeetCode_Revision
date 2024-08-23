Approach 1: Maximum Subarray O(n^2)

int maxSubArray(vector<int> &nums)
    {
        // find the subarraywith the largest sum, and return its sum.
        int sum = 0;
        int maximum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                maximum = max(sum, maximum);
            }
        }
        return maximum;
    }
    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    
    Kadane's Algorithm



    
    int  maxSubArray(vector<int> &nums){
        int maximumSum = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maximumSum)
            {
                maximumSum = sum;
            }
            // if sum negative then assign to 0
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maximumSum;
    }