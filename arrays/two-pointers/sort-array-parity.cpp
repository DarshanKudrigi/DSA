// approach: Two Pointers

// Question: Given an array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// Example 1:
// Input: nums = [1,4,3,2]
// Output: 4
// Explanation: All possible pairings (ignoring the ordering of elements) are:

// 1. (1,4), (2,3) -> min(1,4) + min(2,3) = 1 + 2 = 3
// 2. (1,3), (2,4) -> min(1,3) + min(2,4) = 1 + 2 = 3
// 3. (1,2), (3,4) -> min(1,2) + min(3,4) = 1 + 3 = 4






class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        int i=0, j =0;
        vector<int> ans;
        while(i<even.size() && j<odd.size()){
            ans.push_back(even[i++]);
            ans.push_back(odd[j++]);
        }
        return ans;
    }
};