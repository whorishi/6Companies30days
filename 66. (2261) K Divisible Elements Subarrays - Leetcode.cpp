/*
Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.
*/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>sv;
        for(int i=0;i<nums.size();i++)
        {
            int cnt=0;
            vector<int>v;
            for(int j=i;j<nums.size();j++) {
                if(nums[j]%p==0 && cnt==k)
                {
                    break;
                }
                else if(nums[j]%p==0 && cnt<k)
                {
                    cnt++;
                }
                v.push_back(nums[j]);
                sv.insert(v);
            }
        }
        return sv.size();
    }
};