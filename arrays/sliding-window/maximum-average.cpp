#include<bits/stdc++.h>

// Find the maximum average of a subarray of size k

// Approach 1: Brute Force
// In this approach, we iterate through the array and for each subarray of size k, we calculate the sum and keep track of the maximum sum found. Finally, we return the maximum sum divided by k to get the maximum average.

// Time Complexity: O(n*k) where n is the size of the input array. We iterate through the array and for each subarray of size k, we calculate the sum which takes O(k) time.


class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();
        double max_sum = INT_MIN; 

        for (int i = 0; i <= n - k; i++) {
            double current_sum = 0;
            
            for (int j = i; j < i + k; j++) {
                current_sum += nums[j];
            }
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        return max_sum / k;
    }
};
