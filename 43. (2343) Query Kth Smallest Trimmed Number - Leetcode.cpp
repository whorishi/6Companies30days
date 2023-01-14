/*
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

* Trim each number in nums to its rightmost trimi digits.
* Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
* Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
*/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries) {
            int a=q[0];
            int tr=q[1];
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int i=0;i<nums.size();i++) {
                string n = nums[i].substr(nums[i].length()-tr,tr);;
                pq.push({n,i});
            }
            pair<string,int> x;
            while(a-- && !pq.empty()) {
                x = pq.top();
                pq.pop();
            }
            ans.push_back(x.second);
        }
        return ans;
    }
};