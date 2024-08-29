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