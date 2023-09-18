class Solution {
public:
    int triangleNumber(vector<int>& A) {
      sort(A.begin(),A.end());
      int n = A.size(), ans = 0;
      for(int i=2; i<n; i++){
        int j = i-1, k = 0;
        while(j>k){
          if(A[k] + A[j] > A[i]){
            ans += j-k;
            j--;
          }else k++;
        }
      }
      return ans;
    }
};