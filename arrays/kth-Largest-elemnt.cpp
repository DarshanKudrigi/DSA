// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.




// You may assume k is always valid, 1 ≤ k ≤ array's length.
// Example 1:
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5

// Example 2:
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4

// Approch: Brute Force
// Time Complexity: O(n*k) where n is the length of the array and k is the number of times we need to find the largest element.


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int largest ;
        int ans;
        while(k>0){
            int n = nums.size();
            largest = nums[0];
            for(int i=0;i<n;i++){
                if( nums[i] > largest){
                    largest = nums[i];
                }
            }
            ans=largest;
            nums.erase(find(nums.begin(), nums.end(), largest));
            k--;
        }
        return ans;
    }
};