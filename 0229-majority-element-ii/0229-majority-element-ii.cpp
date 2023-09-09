class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), num1 = -1, num2 = -1, countNum1 = 0, countNum2 = 0;

        for(int i=0; i<nums.size(); i++){
            if(num1 == nums[i]) countNum1++;
            else if(num2 == nums[i]) countNum2++;
            else if(countNum1 == 0) num1 = nums[i], countNum1++;
            else if(countNum2 == 0) num2 = nums[i], countNum2++;
            else countNum1--, countNum2--;
        }

        vector<int> ans;
        countNum1 = 0, countNum2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == num1) countNum1++;
            else if(nums[i] == num2) countNum2++;
        }

        if(countNum1 > n/3) ans.push_back(num1);
        if(countNum2 > n/3) ans.push_back(num2);

        return ans;
    }
};