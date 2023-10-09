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

    static bool comp(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

    void solve(TreeNode* root, map<int,vector<pair<int,int>>>& mp, int w, int h){
        if(!root) return;
        mp[w].push_back({h,root->val});
        solve(root->left,mp,w-1,h+1);
        solve(root->right,mp,w+1,h+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> ans;
        vector<pair<int,int>> temp1;
        vector<int> temp2;
        solve(root,mp,0,0);

        for(auto i: mp){
            temp1 = i.second;
            sort(temp1.begin(),temp1.end(),comp);
            for(int k=0; k<temp1.size(); k++){
                temp2.push_back(temp1[k].second);
            }
            ans.push_back(temp2);
            temp2.resize(0);
        }

        return ans;
    }
};