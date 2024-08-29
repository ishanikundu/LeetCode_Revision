Question States :https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

You have been given a string and you have to find the longest substring 
the Substring which you choose must have unique character and you have to return longest length of substring 

s = [AABCDEAB]

int longestSubstring(string s){
    // store char and indx
    unordered_map<char,int>mp;
    int start = 0;
    int maximum = 0;
    for(int i = 0; i < s.length(); i++){
       
       if(mp.find(s[i])!= mp.end()){      char is present in map --> extract its index where the prev occurence
            start = mp[s[i]] + 1;
       }
       maximum = max(maximum,i - start + 1);
        mp[s[i]] = i;
    }
return maximum;
}