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

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>& mp, int& k, int i, int j){
        if(k < 0 || i>j) return NULL;
        int idx = mp[postorder[k]];
        TreeNode* node = new TreeNode(postorder[k--]);
        node->right = solve(postorder,inorder,mp,k,idx+1,j);
        node->left = solve(postorder,inorder,mp,k,i,idx-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int k = inorder.size()-1;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        return solve(postorder,inorder,mp,k,0,inorder.size()-1);
    }
};