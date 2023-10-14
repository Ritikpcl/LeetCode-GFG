class Solution {
public:
    
    bool check(string& a, string& b){
        if(a.length() != b.length()) return false;
        int i = 0, flag = 1;
        while(i<a.length()){
            if(a[i] != b[i]){
                if(flag) {
                    flag = false;
                }else return false;
            }
            i++;
        }
        return true;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> lis(n,1), parent(n,0);
        vector<string> ans;
        int maxLen = 1, idx = 0;
        for(int i=0; i<n; i++){
            parent[i] = i;
            for(int j=i-1; j>=0; j--){
                if(groups[i] != groups[j] && check(words[i],words[j]) && lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                    
                    if(maxLen < lis[i]){
                        maxLen = lis[i];
                        idx = i;
                    }

                    parent[i] = j; 
                }
            }
        }

        ans.push_back(words[idx]);
        while(parent[idx] != idx){
            idx = parent[idx];
            ans.push_back(words[idx]);
        }
     
        reverse(ans.begin(),ans.end());
        
        return ans; 
    }
};