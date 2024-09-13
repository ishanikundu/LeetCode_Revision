constraint : 
i. Password must be between -> A=65 to Z=90
ii. PassWord must be between  -> a=97 to z = 122
iii. Space including -> 32 Ascii Value
No special character included 
and it must be 2digit and 3 digit 
eg 2digit = 67 ='A', 3digit = 122 = 'z'

password =
    String reverseNum = '5010117940151137'
    soln : if we reverse '7311510497110105'
        '.' passWord =  Ishani Kundu

--------------------------------------

Approach :



string password(string & reverseNum){
//  store a copy
string nums = reverseNum
// reverseNum to be reverse to get the actual order number
reverse(nums.begin(),nums.end());
int n = nums.size();
string password = "";
while(i < n){
    // 3digit
    if(i+2 < n && nums[i] == '1'){
        // form the substring
        int asciiValue = stoi(nums.substr(i,3));
        if(asciiValue >= 32 && asciiValue=<122){
            password += static_cast<char>(asciiValue);
            i = i+3;
            continue;
        }
    }
    if(i+1 < n && nums[i] != '0'){
        // 2digit
        int asciiValue = stoi(nums.substr(i, 2));
        if (asciiValue >= 32 &&asciiValue =< 122)
        {
            password += static_cast<char>(asciiValue);
            i = i + 2;
            continue;
        }
    }
    i++;
  }
  return password;
} 
                                    