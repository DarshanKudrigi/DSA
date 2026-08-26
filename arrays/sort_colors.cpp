#include <vector>
#include <algorithm> // For std::swap

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                std::swap(nums[mid], nums[high]);
                high--;
                // Do not increment mid here, as the swapped element 
                // from 'high' needs to be evaluated in the next iteration.
            }
        }
    }
};
 