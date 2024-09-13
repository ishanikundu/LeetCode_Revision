Approach 1 : Using LPS

// step 1 : Given a string s
// step 2: check if S can be constructed by taking "a" substring of it
//     // step 3:  appending multiple copies of the substring together.
int n = s.length();
vector<int> lps(n, 0);
int i = 1;
int length = 0;
while (i < n)
{
    if (s[i] == s[length])
    {
        length++;
        lps[i] = length;
        i++;
    }
    else if (length == 0)
    {
        lps[i] = 0;
        i++;
    }
    else
        length = lps[length - 1];
}
int smallestStr = n - lps[n - 1];
return (smallestStr < n && n % smallestStr == 0);


INTUITION :

i.through LPS array we will get the longest Prefix and suffix ie LPS[n - 1]
ii. From there by deducting =>   n - LPS[n-1]  we get smallest prefix and suffix
iii. And check that whether it is divisible by the answer that  we get from (ii)


## significance of smallestStr < n :

Example 2 :
String "aaaaaa" Length Calculation :
n = 6 LPS Array : [ 0, 1, 2, 3, 4, 5 ]
lps[5] = 5 smallestStr = n - lps[5] = 6 - 5 = 1 
Condition Check : smallestStr = 1
1 < 6(True) 
Here, 
"aaaaaa" can be constructed by repeating "a", which is a proper substring.

Example 3 : String "abc" Length Calculation :
n = 3 LPS Array : [ 0, 0, 0 ] lps[2] = 0 smallestStr = n - lps[2] = 3 - 0 = 3 
Condition Check : smallestStr = 3 
3 < 3(False)
Here,
smallestStr == n, indicating that the smallest repeating substring is the entire string itself.Therefore, "abc" cannot be constructed by repeating a smaller substring.