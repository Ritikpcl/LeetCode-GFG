class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> lis(n,1);
        vector<string> ans;
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(groups[i] != groups[j] && lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                }
            }
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            if(maxi < lis[i]){
                ans.push_back(words[i]);
                maxi = lis[i];
            }
        }
        
        return ans;
    }
};