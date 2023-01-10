/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int rev(int num)
    {
        string s = to_string(num);
        reverse(s.begin(),s.end());
        int y = stoi(s);
        return y;
    }
    
    int countNicePairs(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i] - rev(nums[i]);
            m[x]++;
        }
        for(auto x:m)
        {
            if(x.second>1)
            {
                cnt=(cnt%1000000007+((x.second)*1LL*(x.second-1)/2)%1000000007)%1000000007;
            } 
        }
        return cnt;
    }
};