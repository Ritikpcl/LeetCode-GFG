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

    int solve(TreeNode* root){
        if(!root) return 1e8;
        if(!root->left && !root->right) return 1;
        int left = solve(root->left);
        int right = solve(root->right);
        return 1 + min(left,right);
    }

    int minDepth(TreeNode* root) {
    // if (root == NULL) return 0;
    // queue<TreeNode*> Q;
    // Q.push(root);
    // int i = 0;
    // while (!Q.empty()) {
    //     i++;
    //     int k = Q.size();
    //     for (int j=0; j<k; j++) {
    //         TreeNode* rt = Q.front();
    //         if (rt->left) Q.push(rt->left);
    //         if (rt->right) Q.push(rt->right);
    //         Q.pop();
    //         if (rt->left==NULL && rt->right==NULL) return i;
    //     }
    // }
    // return -1; //For the compiler thing. The code never runs here
        
        if(!root) return 0;
        return solve(root);
    }
};