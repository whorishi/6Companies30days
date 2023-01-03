/*
You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

    0 <= i < j <= n - 1 and
    nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
    
Return the number of pairs that satisfy the conditions.
*/

//uding policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans=0;
        int n=nums1.size();
        oset<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            int k=nums1[i]-nums2[i]+diff;
            long long temp = s.order_of_key({k,INT_MAX});
            ans+=temp;
            s.insert({nums1[i]-nums2[i],i});
        }
        return ans;
    }
};
/*
nums1[i] -nums2[i] <= nums1[j] - nums2[j] +  diff
*/