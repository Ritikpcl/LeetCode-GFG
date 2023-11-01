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
private:
    vector<int>res;
    int maxSeq = 0;
    int currSeq = 0;
    int prev = -1;
    void inorderTraversal(TreeNode* root)
    {
        if(!root) return;

        inorderTraversal(root->left);
        
        if(prev == -1 || root->val == prev)
        {
            currSeq++;
            if(prev == -1) prev = root->val;
        }
        else
        {
            maxSeq = max(maxSeq, currSeq);
            currSeq = 1;
            prev = root->val;
        }

        if(currSeq > maxSeq)
        {
            res.clear();
            res.push_back(root->val);
        }
        else if(currSeq == maxSeq)
        {
            res.push_back(root->val);
        }
        
        inorderTraversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        inorderTraversal(root);
        return res;
    }
};