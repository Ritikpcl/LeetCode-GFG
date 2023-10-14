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

    TreeNode* rightMost(TreeNode* root){
        if(!root->right) return root;
        return rightMost(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* prev = root;
        while(root){
            if(root->left){
                prev = root;
                root = root->left;
                TreeNode* node = rightMost(root);
                node->right = prev;
                prev->left = NULL;
                prev = root;
            }else{
                ans.push_back(root->val);
                root = root->right;
            } 
        }
        return ans;
    }
};