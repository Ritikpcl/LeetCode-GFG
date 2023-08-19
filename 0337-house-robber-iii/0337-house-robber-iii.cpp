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

    int solve(TreeNode* root, bool prev, map<pair<TreeNode*,int>,int>& dp){
        if(!root) return 0;
        if(dp.find({root,prev}) != dp.end()) return dp[{root,prev}];
        int not_take = solve(root->left,false,dp) + solve(root->right,false,dp);
        int take = 0;
        if(prev == false){
            take = root->val + solve(root->left,true,dp) + solve(root->right,true,dp);
        }

        return dp[{root,prev}] = max(take,not_take);
    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>,int> dp;
        return solve(root,false,dp);
    }
};