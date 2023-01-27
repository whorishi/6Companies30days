/*
Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
*/

class Solution {
public:
    vector<int>orig;
    vector<int>shuffled;
    Solution(vector<int>& nums) {
        for(auto ele:nums){
            orig.push_back(ele);
            shuffled.push_back(ele);
        }
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        int x = orig.size();
        int i,j;
        i=rand()%x;
        do {
            j=rand()%x;
        }while(j==i);
        swap(shuffled[i],shuffled[j]);
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */