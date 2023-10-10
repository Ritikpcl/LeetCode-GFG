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
    void solve(TreeNode* root, int& sum, int num){
        if(!root) return;
        
        num = num*10 + root->val;
        if(!root->left && !root->right) sum += num;
        solve(root->left,sum,num);
        solve(root->right,sum,num);
        num = num/10;
    } 


    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};