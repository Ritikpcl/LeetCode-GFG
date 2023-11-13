class Solution {
public:
    string sortVowels(string s) {
        
        unordered_map<char,int> mp;
        string d = "AEIOUaeiou";
        
        for(int i=0; i<10; i++){
            mp[d[i]]=1;
        }
        
        vector<char> v;
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]]) v.push_back(s[i]);
        }
        
        sort(v.begin(),v.end());
        int k = 0;
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]]){
                s[i] = v[k++];
            }
        }
        
        return s;
    }
};