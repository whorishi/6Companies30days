/*
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
*/

class Solution {
public:
    
    int findIntegers(int n) {
        int sum=0;
        vector<int>dp(32,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<32;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        int k=30,pre_bit=0;
        while(k>=0)
        {
            if(n&(1<<k)) {
                sum+=dp[k];
                if(pre_bit) return sum;
                pre_bit=1;
            }
            else
            {
                pre_bit=0;
            }
            --k;
        }
        return sum+1;
        
    }
};