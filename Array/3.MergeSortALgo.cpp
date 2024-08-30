class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSortArray(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSortArray(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSortArray(nums, left, mid);
            mergeSortArray(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        // +1 used as mid to be included
        int lSize = mid - left + 1;
        int rSize = right - mid;
        vector<int> leftArray(lSize);
        vector<int> rightArray(rSize);

        for (int i = 0; i < lSize; i++)
        {
            leftArray[i] = nums[left + i];
        }
        for (int j = 0; j < rSize; j++)
        {
            rightArray[j] = nums[mid + 1 + j];
        }
        int ptr1 = 0;
        int ptr2 = 0;
        int k = left;
        while (ptr1 < lSize && ptr2 < rSize)
        {
            if (leftArray[ptr1] <= rightArray[ptr2])
            {
                nums[k] = leftArray[ptr1];
                ptr1++;
            }
            else
            {
                nums[k] = rightArray[ptr2];
                ptr2++;
            }
            k++;
        }

        while (ptr1 < lSize)
        {
            nums[k] = leftArray[ptr1];
            ptr1++;
            k++;
        }
        while (ptr2 < rSize)
        {
            nums[k] = rightArray[ptr2];
            ptr2++;
            k++;
        }
    }
};