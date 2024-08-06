
Solution :

    n = 5 n + 1 = 6 integer is in the range[1, n] inclusive.nums = [ 1, 4, 2, 3, 4, 5 ] ^
                                                                   desire : to find the number which is repeating twice;
Donot taking space as a cossideration

    map<int, int>
        mp;

ele->freq 1->1 2->1 3->1 4->2 5->1 space : 0(n)
            Time : 0(1)

                freq
        > 1
    ? print that ele->val
    : -1;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -int checkFreq(vector<int> nums)
{

    map<int, int> mp;

    *frequency

        for (auto i : nums)
    {

        mp[nums[i]]++;
    }
    for (auto i : mp)
    {

        if (i.second > 1)
        {

            return i.first;
        }
    }
    return -1;
}

Time complexcity : since map = O(log n) if used unorderedMap = 0(n)
                       space complexcity : 0(n)

--------------------------------------------------------------------------
 soln 2:
 
 int findDuplicate(vector<int> & nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}
Time complexcity = 0(n)
Space = O(1)