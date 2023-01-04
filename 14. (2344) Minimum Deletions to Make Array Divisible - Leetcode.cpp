/*
You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.

Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.

Note that an integer x divides y if y % x == 0.
*/

class Solution {
public:
    int findGCD(vector<int>& arr)
    {
        int n=arr.size();
        int result = arr[0];
        for (int i = 1; i < n; i++)
        {
            result = gcd(arr[i], result);

            if(result == 1)
            {
                return 1;
            }
        }
        return result;
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x = findGCD(numsDivide);
        //cout<<x<<endl;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(x%nums[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};