[7,0,-2,0,-1]

it will be like two pointer approach 
one is prefix 
second is suffix  


[7,0,-2,0,2,-1]
 p         s
 
p          s       pro = max(pro,max(p,s))
7         -1        0,max(7,-1)
0==1      2*-1      7,max(1,-1)
1*-2      0 ==1     7,max(-2,1)
1         -2*1      7,max(1,-2)
..

int maximumProductSubarray(vector<int>nums){
    double  maximum = INT_MIN;
    int n = nums.size();
    double  prefix = 1;
    double suffix = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - 1 - i];
        maximum = max(maximum, max(prefix, suffix));
    }

    return maximum;
}


various error was occuring with taste case :
     [-2]  for this maximum has been initialized to INT_MIN
     [0,10,10,10,10,10,-10,0,10]  -> for this test case :  double is used as overflow cond could be seen
                                    