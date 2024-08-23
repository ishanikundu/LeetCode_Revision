Approach 1 : Brute Force

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
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Approach : Slidding Window

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{

  if (k <= 1)
    return 0;
  // Handle edge case where k is 1 or less.
  int right = 0;
  int left = 0;
  int product = 1;
  int count = 0;
  while (right < size)
  {
    product *= nums[right];
    while (product >= k && left <= right)
    {
      product /= nums[left];
      left++;
    }
    count += right - left + 1;
    right++;
  }
  return count;
}