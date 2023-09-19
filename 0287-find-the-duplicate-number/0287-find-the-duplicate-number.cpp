class Solution {
public:

// /* Approach :- Put the element at their corresponding indexes until one of them meet its duplcate */

    int findDuplicate(vector<int>& nums) {
//         int i=0;
//         while(nums[i] != nums[nums[i]-1] || nums[i] == i+1){  //i-1 because 0th index
//             if(nums[i] == i+1) i++;
//             swap(nums[i],nums[nums[i]-1]);
//         }
//         return nums[i];
//     }


        // for(int i=0; i<A.size(); i++){
        //     if(A[abs(A[i])-1] < 0) return abs(A[i]);
        //     else A[abs(A[i])-1] *= -1;
        // }
        // return -1;

        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};