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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& mp, int& k, int i, int j){
        if(k >= preorder.size() || i>j) return NULL;
        int idx = mp[preorder[k]];
        TreeNode* node = new TreeNode(preorder[k++]);
        node->left = solve(preorder,inorder,mp,k,i,idx-1);
        node->right = solve(preorder,inorder,mp,k,idx+1,j);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int k = 0;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        return solve(preorder,inorder,mp,k,0,inorder.size()-1);
    }
};