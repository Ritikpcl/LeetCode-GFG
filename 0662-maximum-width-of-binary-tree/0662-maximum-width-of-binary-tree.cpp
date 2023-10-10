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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(q.size()){
            bool flag = true;
            int size = q.size();
            int mini = 0, maxi = 0;
            while(size--){
                TreeNode* node = q.front().first;
                int w = q.front().second;
                q.pop();

                if(flag){
                    mini = w;
                    flag = false;
                }
                
                if(node->left) q.push({node->left,(long long)2*(w-mini)+1});
                if(node->right) q.push({node->right,(long long)2*(w-mini)+2});
                maxi = max(maxi,w);
            }
            ans = max(ans,maxi-mini+1);
        }
        return ans;
    }
};