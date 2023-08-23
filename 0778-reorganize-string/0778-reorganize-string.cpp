class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        vector<int> v(26,0);
        vector<char> ans(n);
        int mostFreq = 0;
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a'] > v[mostFreq]) mostFreq = s[i] - 'a';
            if(v[s[i]-'a'] > ceil(n/2.0)) return "";
        }

        int j = 0;

        while(v[mostFreq] > 0){
            ans[j] = 'a' + mostFreq;
            j = (j+2);
            v[mostFreq]--;
        }


        for(int i=0; i<26; i++){
            while(v[i]>0){
                if(j >= n) j = 1;
                ans[j] = 'a'+i;
                j = (j+2) ;
                v[i]--;
            }
        }

        string res = "";
        for(int i=0; i<n; i++) res += ans[i];
        return res;
    }
};