Approach 1: Brute Force 


int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int product = 1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        product = 1;
        for (int j = i; j < nums.size(); j++)
        {
            product = product * nums[j];
            if (product < k)
            {
                count++;
            }
        }
    }
    return count;
}
----------------------------------------------------

