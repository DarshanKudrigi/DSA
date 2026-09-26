#include<bits/stdc++.h>

// Find the maximum average of a subarray of size k

// Question Link: https://leetcode.com/problems/maximum-average-subarray-i/

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

// Approach 2: Sliding Window

// In this approach, we use a sliding window of size k to calculate the sum of the subarray. We first calculate the sum of the first k elements and then slide the window by removing the first element and adding the next element in the array. We keep track of the maximum sum found during this process. Finally, we return the maximum sum divided by k to get the maximum average.


class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();
        double current_sum = 0;
        
        
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        
        
        for (int i = k; i < n; i++) {
            current_sum += nums[i] - nums[i - k]; // Add the next element and remove the first element of the previous window
            max_sum = std::max(max_sum, current_sum); // Update max_sum if current_sum is greater
        }
        
        return max_sum / k; 
    }
};

// acumulate function is used to calculate the sum of the first k elements in a more efficient way.

//auumulate function which is defined in the <numeric> header file, takes three arguments: the starting iterator, the ending iterator, and an initial value. It calculates the sum of the elements in the range [first, last) and returns the result. In this case, we use it to calculate the sum of the first k elements of the nums vector.


// Approach 3: Optimized Sliding Window

// In this approach, we use a sliding window of size k to calculate the sum of the subarray. We first calculate the sum of the first k elements and then slide the window by removing the first element and adding the next element in the array. We keep track of the maximum sum found during this process. Finally, we return the maximum sum divided by k to get the maximum average.

//Time complexity for the accumulate function is O(k) where k is the size of the subarray. The overall time complexity of this approach is O(n) where n is the size of the input array.


class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();
        double current_sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0); // Calculate the sum of the first k elements
        double max_sum = current_sum; // Initialize max_sum with the sum of the first k elements
        
        for (int i = k; i < n; i++) {
            current_sum += nums[i] - nums[i - k]; // Slide the window by adding the next element and removing the first element of the previous window
            max_sum = std::max(max_sum, current_sum); // Update max_sum if current_sum is greater
        }
        
        return max_sum / k; // Return the maximum average
    }
};







class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double current_sum = 0;
        
        
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        int l = 0;
        int r = k;
        
        while(r<n){
            current_sum += nums[r];
            current_sum -= nums[l];
            max_sum = std::max(max_sum, current_sum); 
            r++;
            l++;
        }
        
        return max_sum / k;
    }
};