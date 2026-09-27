// Maximum Consecutive Ones

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Question Link: https://leetcode.com/problems/max-consecutive-ones/

// Approach 1: Brute Force

// In this approach, we iterate through the array and for each element, we check if it is 1. If it is, we increment a counter to keep track of the current streak of consecutive 1's. If we encounter a 0, we reset the counter to 0. We also keep track of the maximum streak found during this process. Finally, we return the maximum streak.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int current_count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current_count++;
                max_count = max(max_count, current_count);
            } else {
                current_count = 0;
            }
        }
        
        return max_count;
    }
};




// Approach 2: Optimized Sliding Window

// In this approach, we use a sliding window to keep track of the current streak of consecutive 1's. We iterate through the array and for each element, we check if it is 1. If it is, we increment a counter to keep track of the current streak of consecutive 1's. If we encounter a 0, we reset the counter to 0. We also keep track of the maximum streak found during this process. Finally, we return the maximum streak.


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int current_count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current_count++;
                max_count = max(max_count, current_count);
            } else {
                current_count = 0;
            }
        }
        
        return max_count;
    }
};



// Approach 3: Two Pointers

// In this approach, we use two pointers to keep track of the current streak of consecutive 1's. We iterate through the array and for each element, we check if it is 1. If it is, we increment a counter to keep track of the current streak of consecutive 1's. If we encounter a 0, we reset the counter to 0. We also keep track of the maximum streak found during this process. Finally, we return the maximum streak.



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int l=0;
        int r=0;
        int n = arr.size();
        int cnt=0;
        int ans=0;
        while(r<n){
            if(arr[l]==1 && arr[r]==1){
                cnt++;
                ans=max(ans,cnt);
                r++;
            }
            else{
                r++;
                l=r;
                cnt=0;
            }
        }
        return ans;
    }
};