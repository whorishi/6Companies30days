/*

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

    F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
        
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

*/


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int val=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            val+=nums[i]*i;
        }
        
        ans=val;
        
        for(int i=0;i<nums.size();i++)
        {
            val = val + sum - nums.size()*nums[nums.size()-i-1];
            ans=max(ans,val);
        }
        
        return ans;
        
    }
};