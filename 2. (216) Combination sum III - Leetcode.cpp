
/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

        *Only numbers 1 through 9 are used.
        *Each number is used at most once.
        
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

*/

class Solution {
public:
    
    void solve(int i, int cursum, int cnt, vector<int>& v, vector<vector<int>>& res, int k, int n)
    {
        if(cnt>k) return;
        if(cursum>n) return;
        if(cnt==k)
        {
            if(cursum==n)
            {
                res.push_back(v);
            }
            return;
        }
        
        for(int j=i+1;j<=9;j++)
        {
            v.push_back(j);
            solve(j,cursum+j,cnt+1,v,res,k,n);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        //vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>v;
        int cnt=0;
        for(int i=1;i<=9;i++)
        {
            v.push_back(i);
            solve(i,i,1,v,res,k,n);
            v.pop_back();
        }
        return res;
    }
};