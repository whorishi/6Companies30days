/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=0;
        int min=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i]>min)
            {
                start=i;
            }
            else
            {
                min=nums[i];
            }
        }
        
        int end=0;
        int max=nums[0];
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<max)
            {
                end=i;
            }
            else
            {
                max=nums[i];
            }
        }
        if(end!=start)
            return end-start+1;
        return 0;
    }
};