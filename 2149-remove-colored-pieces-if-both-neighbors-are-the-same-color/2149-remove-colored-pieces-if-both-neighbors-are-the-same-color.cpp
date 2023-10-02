class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int> A,B;
        int cnt = 0;
        for(int i=0; i<colors.length(); i++){
            if(colors[i] == 'A'){
                cnt++;
            }else cnt = 0;
            A.push_back(cnt);
        }

        cnt = 0;
        for(int i=0; i<colors.length(); i++){
            if(colors[i] == 'B'){
                cnt++;
            }else cnt = 0;
            B.push_back(cnt);
        }

        int a = 0;
        for(int i=0; i<A.size(); i++){
            if(A[i] >= 3) a++;
        }

        int b = 0;
        for(int i=0; i<B.size(); i++){
            if(B[i] >= 3) b++;
        }

        if(a > b) return true;
        return false;
    }
};