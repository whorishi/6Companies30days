/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX;
        int b=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=a)
                a=nums[i];
            else if(nums[i]<=b)
                b=nums[i];
            else
                return true;
        }
        return false;
    }
};