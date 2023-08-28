class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
        long long totalSum = accumulate(nums.begin(),nums.end(),(long long)0);
        if(totalSum < target) return -1;
        
        sort(nums.begin(),nums.end());
        int ans = 0;
        while(target>0){
            int x = nums.back();
            nums.pop_back();

            if(totalSum - x >= target) {
                totalSum -= x;
            }else{
                if(x <= target){
                    totalSum -= x;
                    target -= x;
                }else{
                    nums.push_back(x/2);
                    nums.push_back(x/2);
                    ans++;
                }
            }
        }

        return ans;
    }
};