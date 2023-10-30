class Solution {
public:

    static bool comp(int& a, int& b){
        
        int cnt1 = 0, cnt2 = 0;
        int x = a, y = b;
        
        while(x){
            cnt1 += (x&1);
            x = x >> 1;
        }

        while(y){
            cnt2 += (y&1);
            y = y >> 1;
        }

        if(cnt1 == cnt2) return a < b;
        return cnt1 < cnt2;

    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};