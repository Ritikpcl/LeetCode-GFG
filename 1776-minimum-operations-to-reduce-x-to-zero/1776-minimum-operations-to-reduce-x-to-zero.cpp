class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum < x) return -1;
        int sum = totalSum - x;
        int n = nums.size(), i = 0, j = 0, s = 0, len = -1;
        while(j < n){
            s += nums[j];

            while(s > sum){
                s -= nums[i++];
            }

            if(s == sum){
                len = max(len,j-i+1);
            }

            j++;
        }

        return len == -1 ? -1 : n - len;
    }
};