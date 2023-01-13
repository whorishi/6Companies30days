/*
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

    * The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
    * A subtree of root is a tree consisting of root and all of its descendants.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans=0;
    
    pair<int,int> solve(TreeNode* root)
    {
        if(!root) return {0,0};
        pair<int,int>p1 = solve(root->left);
        pair<int,int>p2 = solve(root->right);
        int sum = root->val + p1.first + p2.first;
        int n = 1 + p1.second + p2.second;
        if(root->val == sum/n) ans++;
        return {sum,n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};