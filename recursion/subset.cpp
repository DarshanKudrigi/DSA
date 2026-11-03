// 78. Subsets

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
    vector<vector<int>> res;
    vector<int> temp;

public:
    void subsetFun(int index, vector<int>& nums) {
        if (index >= nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        subsetFun(index + 1, nums);

        temp.pop_back();
        subsetFun(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        temp.clear();

        subsetFun(0, nums);

        return res;
    }
};