// Maximum Sum of Distinct Subarrays With Length K

// Given an integer array nums and an integer k, return the maximum possible sum of a distinct subarray of nums of length k. If no such sum exists, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array. A distinct subarray is a subarray that contains only unique elements.

// Example 1:
// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The distinct subarrays of size 3 are:
// - [1,5,4] with sum 10
// - [5,4,2] with sum 11
// - [4,2,9] with sum 15

// Example 2:
// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: There are no distinct subarrays of size 3.



// Constraints:
// 1 <= k <= nums.length <= 10^5



class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;

        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> st;
            long long sum = 0;
            bool valid = true;

            for (int j = i; j < i + k; j++) {
                if (st.count(nums[j])) {
                    valid = false;
                    break;
                }
                st.insert(nums[j]);
                sum += nums[j];
            }
            if (valid) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};