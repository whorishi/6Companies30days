/*
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= nums1 < nums2 <= right .
nums1 and nums2 are both prime numbers.
nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.

A number greater than 1 is called prime if it is only divisible by 1 and itself.
*/

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int flag;
        vector<int>v={-1,-1};
        int pre=-1;
        int ans=INT_MAX;
        
        for(int i=left;i<=right;i++)
        {
            if(i==1 || i==0)
                continue;
            flag=1;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    flag=0;
                    break;
                }
            }
            
            if(flag==1)
            {
                int x=i;
                if(pre!=-1)
                {
                    if(x-pre < ans)
                    {
                        ans = x-pre;
                        v={pre,x};
                    }
                }
                pre=x;
            }
        }
        return v;
    }
};