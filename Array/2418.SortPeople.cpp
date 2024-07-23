// link:https://leetcode.com/problems/sort-the-people/description/

// Here we have to use lambda function or customized according to our problem 
// syntax : [capture](paramater)->return_type{body}

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int,string>>heightNamePair;
       vector<string>ans;
       int n = heights.size();
       //   put the elements in the heightNamePair
       for (int i = 0; i < n; i++)
       {
           heightNamePair.push_back({heights[i], names[i]});
       }

       //   comparator func or lambda func
       // syntax for it is  :    [capture](parameter)-> return_type {body};

       sort(heightNamePair.begin(), heightNamePair.end(),
            [](const pair<int, string> &a,
               const pair<int, string> &b)
            {
                // we have used first bcoz we have
                // to arrange inaccordance with height
                // ie first if it would have been name them it would be second
                return a.first > b.first;
            });
       //   now we have sorted height and to arrange name
       for (int i = 0; i < heightNamePair.size(); i++)
       {
           ans.push_back(heightNamePair[i].second);
       }

       return ans;
    }
};
     