/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

    *Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
    *All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m,m1;
        
        for(auto ele:nums)
            m[ele]++;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==0)
                continue;
            m[nums[i]]--;
            if(m1[nums[i]-1]>0)
            {
                m1[nums[i]-1]--;
                m1[nums[i]]++;
            }
            else if(m[nums[i]+1]>0 && m[nums[i]+2]>0)
            {
                m[nums[i]+1]--;
                m[nums[i]+2]--;
                m1[nums[i]+2]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};