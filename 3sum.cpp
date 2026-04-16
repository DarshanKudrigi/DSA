
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

/*
Important Notes for 3-Sum Brute Force:

1. Use 3 nested loops to generate all possible triplets.

2. Condition:
   arr[i] + arr[j] + arr[k] == 0

3. Use set<vector<int>> to store only unique triplets.

4. Sort each triplet before inserting into set
   so duplicates like [1,-1,0] and [-1,0,1] become same.

5. Convert set into vector<vector<int>> as final answer.

6. Time Complexity:
   O(n^3)

7. Space Complexity:
   O(k)   // k = number of unique triplets

8. Best for learning brute force approach.

9. Better optimal solution:
   Sorting + Two Pointer = O(n^2)
*/