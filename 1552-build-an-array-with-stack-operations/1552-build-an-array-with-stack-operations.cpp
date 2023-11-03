class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int x = 1;
        vector<string> v;
        for(int i=0; i<target.size(); i++){
            int cnt = 0;
            while(x < target[i]){
                v.push_back("Push");
                cnt++;
                x++;
            }
            while(cnt--){
                v.push_back("Pop");
            }
            v.push_back("Push");
            x++;
        }
        return v;
    }
};