

Step-by-Step Example:
Example Input:
a = "abcd"
b = "cdabcdab"
Step 1: Calculate Minimum Number of Repeats
Calculate Lengths:

lenA = 4 (length of "abcd")
lenB = 8 (length of "cdabcdab")
Compute Minimum Repeats:

minRepeats
=
⌈8/4⌉= 2
minRepeats=⌈4/8⌉=2
Hence, we need at least 2 repetitions of a to cover b.
Step 2: Construct the Repeated String
Repeat a for minRepeats:

Repeat a 2 times:
"abcd" + "abcd" = "abcdabcd"
Check the Additional Repeat:

Repeat a one more time to get:
"abcdabcdabcd"
Step 3: Check if b is a Substring
Check in the Repeated Strings:

"abcdabcd" (does not contain "cdabcdab")
"abcdabcdabcd" (contains "cdabcdab")
Return the Result:

Since "cdabcdab" is found in the string "abcdabcdabcd", the result is the number of repetitions required:
Minimum number of repetitions: 3


int repeatedStringMatch(string a, string b)
{
    int lenA = a.size();
    int lenB = b.size();
    // Use the formula = lenB/LenA
    int minRepeate = (lenB + lenA - 1) / lenA;
    for (int i = minRepeate; i <= minRepeate + 1; ++i)
    {
        string repeatedA;
        for (int j = 0; j < i; j++)
        {
            repeatedA += a;
        }
        if (repeatedA.find(b) != string::npos)
        {
            return i;
        }
    }
    return -1;
};