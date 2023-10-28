class Solution {
public:
    
    map<char,vector<char>> mp;
    map<pair<char,int>, long long> dp;
    int M = 1e9 + 7;
    
    long long solve(int n, int l, char c)
    {
        if(l == n) return 1;
        
        if(dp.find({c,l}) != dp.end()) return dp[{c,l}];
        long long count = 0;
        for(auto i: mp[c])
            count += solve(n,l+1,i) % M;
        
        return dp[{c,l}] = count % M;
    }
    
    int countVowelPermutation(int n) {
        
        mp['a'].push_back('e');
        
        mp['e'].push_back('a');
        mp['e'].push_back('i');
        
        mp['i'].push_back('a');
        mp['i'].push_back('e');
        mp['i'].push_back('o');
        mp['i'].push_back('u');
        
        mp['o'].push_back('i');
        mp['o'].push_back('u');
        
        mp['u'].push_back('a');
    
        string s = "aeiou";
        long long count = 0;
        
        for(int i=0; i<5; i++)
            count += solve(n,1,s[i]);
        
        return count % M;
    }
};