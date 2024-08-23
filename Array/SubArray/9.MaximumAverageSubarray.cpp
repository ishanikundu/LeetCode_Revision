Approach : Brute Force


  double findMaxAverage(vector<int>& nums, int k) {
        // length = k
        // return this max Avg value
        double maximum;
        double sum = 0;
        int len = 0;
        double avg;
        for(int i = 0; i < nums.size(); i++){
            sum = 0;
            len = 0;
            for(int j = i; j < nums.size(); j++){
                len++;
                sum += nums[j];
                if(len == k){
                    avg = sum/k;
                }
                maximum = max(maximum,avg);
            }
        }
        return maximum;
    }


----------------------------------------------------------


Approach :Sliding Window

double findMaxAverage(vector<int> &nums, int k)
{
    double prefixSum;
    int right = 0;
    int left = 0;
    double maximum = -DBL_MAX;
    while (right < nums.size())
    {
        prefixSum += nums[right];
        while (right - left + 1 > k && left <= right)
        {
            prefixSum -= nums[left];
            left++;
        }
        if (right - left + 1 == k)
        {
            double avg = prefixSum / k;
            maximum = max(maximum, avg);
        }
        right++;
    }
    return maximum;
}