/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preOrder(TreeNode* root, string& s){
        if(!root) return;
        s += "(" + to_string(root->val) + ",";
        if(root->left && root->right) s += "3";
        else if(root->left && !root->right) s += "1";
        else if(!root->left && root->right) s += "2";
        else s += "0";
        s += ")";
        preOrder(root->left,s);
        preOrder(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preOrder(root,s);
        cout<<s<<endl;
        return s;
    }

    pair<int,int> resolve(string& data, int& i){
        
        pair<int,int> num;

        string s="";
        i++;
        while(data[i] != ','){
            s += data[i++];
        }
        num.first = stoi(s);

        s = "";
        i++;
        while(data[i] != ')'){
            s += data[i++];
        }
        num.second = stoi(s);
        i++;

        return num;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<pair<TreeNode*,int>> st;
        vector<pair<int,int>> v;
        int idx = 0;
        TreeNode* root = NULL;
        while(idx < data.length()){

            pair<int,int> num = resolve(data,idx);
            TreeNode* node = new TreeNode(num.first);
            if(root == NULL) root = node;

            if(st.size()){
                TreeNode* parent = st.top().first;
                int child = st.top().second;
                st.pop();

                if(child == 3){
                    parent->left = node;
                    child = 2;
                    st.push({parent,child});
                }else if(child == 1){
                    parent->left = node;
                }else if(child == 2){
                    parent->right = node;
                }
            }
            if(num.second) st.push({node,num.second});
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));