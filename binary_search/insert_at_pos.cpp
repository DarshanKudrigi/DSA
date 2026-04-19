#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        if (target <= nums[0]) return 0;
        if (target >= nums[n - 1]) return n;

        for (int i = 0; i < n - 1; i++) {
            int prev = nums[i];
            int next = nums[i + 1];

            if (prev == target) return i;
            if (next == target) return i + 1;

            if (target > prev && target < next) {
                return i + 1;
            }
        }

        return n;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 5, 6};
    int target;

    cout << "Enter target: ";
    cin >> target;

    int ans = obj.searchInsert(nums, target);

    cout << "Insert/Search Position: " << ans << endl;

    return 0;
}




// Important Notes for Search Insert Position:
// - The array is sorted in ascending order.
// - If target is found, return its index.
// - If target is not found, return the index where it would be inserted to maintain sorted order.
// - Check edge cases for target less than first element and greater than last element.
// - Time Complexity: O(n) due to linear search.
// - Space Complexity: O(1) as we are using constant extra space.

// best approach: Binary Search with O(log n) time complexity.
