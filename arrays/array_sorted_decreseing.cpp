#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        int p = n - 1; // Start filling from the back
        
        while (left <= right) {
            // Compare squared values directly to avoid std::abs overhead
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[p] = leftSquare;
                left++;
            } else {
                result[p] = rightSquare;
                right--;
            }
            p--;
        }
        return result;
    }
};
