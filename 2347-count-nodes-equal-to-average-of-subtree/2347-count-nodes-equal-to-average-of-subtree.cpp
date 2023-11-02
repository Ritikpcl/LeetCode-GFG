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
    int ans = 0;

    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> left,right;
        left = solve(root->left);
        right = solve(root->right);
        int sum = left.first + right.first + root->val;
        int numNodes = left.second + right.second + 1;

        if(sum/numNodes == root->val) ans++;
        return {sum,numNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};