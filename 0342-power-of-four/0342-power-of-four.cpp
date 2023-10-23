class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n<4 || n&1) return false;
        n = n >> 1;

        bool flag = false;
        int i = 1;
        while(n){
            if(n&1){
                if(i&1) return false;
                else if(flag) return false;
                else flag = true;
            }
            n = n >> 1;
            i++;
        }

        return true;
    }
};