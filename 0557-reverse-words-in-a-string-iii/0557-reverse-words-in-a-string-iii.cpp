class Solution {
public:
    string reverseWords(string s) {
        
        string temp="";
        string ans = "";
        for(int i=0; i<s.length();)
        {
            while(i<s.length() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            if(i!=s.length()) ans += " ";
            temp = "";
            i++;
        }
        return ans;
    }
};