class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int n = A.size();
        int start = -1, end = -1, maxi = A[0], mini = A[n-1];
        
        for(int i=1; i<n; i++){
            if(maxi > A[i]) end = i;
            maxi = max(maxi, A[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            if(mini < A[i]) start = i;
            mini = min(mini,A[i]);
        }
        
        if(start == -1) return 0;
        return end-start+1;
    }
};