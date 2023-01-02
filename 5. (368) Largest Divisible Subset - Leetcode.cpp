/*

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

   * answer[i] % answer[j] == 0, or
   * answer[j] % answer[i] == 0
   
If there are multiple solutions, return any of them.

*/



vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        vector<int> hash(n, 0);
        int ind = 0, cnt = 0;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=n-1;j>=0;j--)
            {
                if(dp[i]<dp[j]+1 && nums[i]%nums[j]==0)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i]>cnt)
            {
                cnt = dp[i];
                ind = i;
            }
        }
        
        vector<int> ans;
        
        while(hash[ind]!=ind)
        {
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        return ans;
    }