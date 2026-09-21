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




// Time Complexity: O(n*k) where n is the size of the input array and k is the length of the subarray. In the worst case, we may have to check all possible subarrays of length k, which takes O(n*k) time.

// Space Complexity: O(k) where k is the length of the subarray. We use an unordered_set to store the elements of the current subarray, which takes O(k) space in the worst case.







// approach 2: Sliding Window + HashSet
// In this approach, we use a sliding window of size k and a hash set to keep track of the distinct elements in the current window. We maintain a running sum of the elements in the window and update the maximum sum whenever we find a valid distinct subarray of size k. If we encounter a duplicate element, we slide the left end of the window to remove elements until the duplicate is removed.
 

// Time Complexity: O(n) where n is the size of the input array. We iterate through the array once, and each element is added and removed from the hash set at most once.


// Space Complexity: O(k) where k is the length of the subarray. We use an unordered_set to store the elements of the current window, which takes O(k) space in the worst case.



class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        
        long long sum = 0;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (st.count(nums[r])) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            st.insert(nums[r]);
            sum += nums[r];

            if (r - l + 1 == k) {
                ans = max(ans, sum);

                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
        }

        return ans;
    }
};




// 






class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        long long sum = 0;
        long long ans = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            mp[nums[r]]++;
            if (r - l + 1 > k) {
                sum -= nums[l];
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                l++;
            }
            if (r - l + 1 == k) {
                if (mp.size() == k) {
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};