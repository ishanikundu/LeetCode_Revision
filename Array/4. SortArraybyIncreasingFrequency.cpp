class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        // Step 1: Count frequencies of each number
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int n = mp.size();
        vector<pair<int, int>> freqPairNum;


        // insert Element in freqPairNum

        for (auto i : mp)
        {
            freqPairNum.push_back({i.second, i.first});
        }

        // Customize Sorting
        // Step 3: Sort by frequency in increasing order, and by number in decreasing order

        sort(freqPairNum.begin(), freqPairNum.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
             if(a.first != b.first){
            //   increasing order
                return a.first < b.first;
             }
             else {
                //decreasing order
                return a.second > b.second;
             } });



        // Step 4: Build the result vector based on sorted frequencies and numbers

        for (int i = 0; i < freqPairNum.size(); i++)
        {
            for (int j = 0; j < freqPairNum[i].first; j++)
            {
                ans.push_back(freqPairNum[i].second);
            }
        }

        return ans;
    }
};

// // how ? vector<pair<int, int>> freqPairNum;
// for (const auto &entry : freq)
// {
//     freqPairNum.push_back({entry.second, entry.first});
// } 
   // cant we write this
    //  int n = mp.size()
    //                     vector<pair<int, int>>freqPairNum;
    // // insert Element in freqPairNum
    // for (int i = 0; i < n; i++)
    // {
    //     freqPairNum.push_back({mp[i].second, nums[i]});
    // }

    // ChatGPT
    // The key issue with using for (int i = 0; i < n; i++) in your second code snippet is that you are treating mp as if it were a vector or an array, while it is actually a map. Maps do not provide direct indexing like arrays or vectors, so you cannot use mp[i] to access elements.

    // Let's clarify why your second approach will not work and provide a correct way to iterate over the map and store elements into a vector of pairs.

    // Issues with Your Approach
    // Maps and Indexing:

    // mp[i] assumes mp is an indexed container like a vector or array, but mp is a map, which does not support direct indexing. Instead, maps use keys to access values.
    // Correct Iteration Over Maps:

    // The correct way to access elements in a map is to use iterators or range-based loops.
    // Correct Way to Populate freqPairNum
    // Given that mp is a map where the key is the number and the value is its frequency, you should iterate over the map using its iterators or a range-based for loop to extract the pairs and populate freqPairNum.
