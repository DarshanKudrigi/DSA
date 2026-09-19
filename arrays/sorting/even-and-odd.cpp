// question link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/

// approach: Two Pointers

// Question: Given a 0-indexed integer array nums, rearrange the values of nums according to the following rules:

// - Sort the values at odd indices of nums in non-increasing order.
// - Sort the values at even indices of nums in non-decreasing order.

// Return the array formed after rearranging the values of nums.

//
// Example 1:
// Input: nums = [4,1,2,3]
// Output: [2,3,4,1]
// Explanation:
// The values at even indices are 4 and 2. We sort them in non-decreasing order to get 2 and 4.

// The values at odd indices are 1 and 3. We sort them in non-increasing order to get 3 and 1.

// Example 2:
// Input: nums = [2,1]
// Output: [2,1]
//

















class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evens;
        vector<int> odds;

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                evens.push_back(nums[i]);
            } else {
                odds.push_back(nums[i]);
            }
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), greater<int>());

        vector<int> result(nums.size());
        int evenIdx = 0, oddIdx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                result[i] = evens[evenIdx++];
            } else {
                result[i] = odds[oddIdx++];
            }
        }

        return result;
    }
};
