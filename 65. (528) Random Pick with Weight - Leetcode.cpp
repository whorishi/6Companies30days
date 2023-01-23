/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
*/

class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        for(auto ele:w)
        {
            if(v.size()==0) v.push_back(ele); 
            else v.push_back(v.back()+ele);
        }
    }
    
    int pickIndex() {
        int randomNum = rand()%v[v.size()-1];
        return upper_bound(v.begin(),v.end(),randomNum) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */