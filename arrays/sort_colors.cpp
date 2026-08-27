// approch: Dutch National Flag Algorithm
// time complexity: O(n) where n is the length of the array
// space complexity: O(1) as we are not using any extra space


// example: nums = [2,0,2,1,1,0] => [0,0,1,1,2,2], nums = [2,0,1] => [0,1,2], nums = [0] => [0], nums = [1] => [1]

// dutuch national flag algorithm is a three-way partitioning algorithm that sorts an array of 0s, 1s, and 2s in a single pass. The algorithm maintains three pointers: low, mid, and high. The low pointer points to the next position where a 0 should be placed, the mid pointer traverses the array, and the high pointer points to the next position where a 2 should be placed. The algorithm swaps elements based on their values and adjusts the pointers accordingly until the entire array is sorted.


#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { 
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
 