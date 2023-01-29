/*
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long>prefix(nums.size()+1);
        prefix[0]=0;
        for(int i=1;i<nums.size()+1;i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        //leftmin
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            if(st.empty())
                left[i]=-1;
            else
                left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            if(st.empty())
                right[i]=nums.size();
            else
                right[i]=st.top();
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int l=left[i];
            int r=right[i];
            long long sum = (prefix[r]-prefix[l+1]);
            long long pro = sum * nums[i];
            ans = max(pro,ans);
        }
        return (int)(ans%1000000007);
    }
};