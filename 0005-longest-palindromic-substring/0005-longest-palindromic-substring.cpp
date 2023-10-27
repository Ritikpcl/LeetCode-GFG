class Solution {
public:
    bool is_palindrome(string s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        unordered_map<char,vector<int>> map;
        int max_len = 1;
        pair<int,int> res = {0,0};
        for(int i=0; i<s.length(); i++) map[s[i]].push_back(i);
        
        for(int i=0; i<s.length(); i++){
            int n = map[s[i]].size();
            for(int j=n-1; map[s[i]][j]>i; j--){
                if(map[s[i]][j]-i >= max_len){
                    if(is_palindrome(s,i,map[s[i]][j])){
                        max_len = map[s[i]][j]-i;
                        res = {i,map[s[i]][j]};
                    }
                }
            }
        }
        int a = res.first;
        int b = res.second;
        return s.substr(a,b-a+1);
    }
};