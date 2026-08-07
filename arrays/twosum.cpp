#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if(nums[i] + nums[j] == target) {
//                     result.push_back(i);
//                     result.push_back(j);
//                     return result;
//                 }
//             }
//         }

//     }
// };

class Solution
{
    public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                result.push_back(mp[complement]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};

int main()
{
    vector<int> arr = {8, 2, 5, 3};

    Solution sol;

    vector<int> ans = sol.twoSum(arr, 11);

    cout << "The indices of the two numbers are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
