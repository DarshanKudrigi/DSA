// This code defines a C++ class `Solution` that contains a method `longestCommonPrefix`. The method takes a vector of strings as input and returns the longest common prefix among those strings.

// The method first checks if the input vector is empty and returns an empty string if it is. It then sorts the strings alphabetically and compares the first and last strings in the sorted order to find the common prefix. The common characters are collected into a result string, which is returned at the end.

// time complexity: O(n log n) due to sorting, where n is the number of strings. The comparison of the first and last strings takes O(m) time, where m is the length of the shortest string. Overall, the time complexity is dominated by the sorting step.

// space complexity: O(1) for the result string, as it only stores the common prefix. The sorting operation may use additional space depending on the implementation of the sort function, but it is generally considered to be O(log n) for in-place sorting algorithms.

// IntroSort : it is a hybrid sorting algorithm that combines quicksort, heapsort, and insertion sort. It is used in the C++ standard library's sort function to provide efficient sorting performance across different types of input data. The algorithm starts with quicksort and switches to heapsort when the recursion depth exceeds a certain level, ensuring that the worst-case time complexity remains O(n log n). For small subarrays, it uses insertion sort for better performance.

// problem number: 14
// problem statement: Given a vector of strings, find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""

// example 3:
// Input: strs = ["interspecies","interstellar","interstate"]
// Output: "inters"



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Handle empty input edge case
        if (strs.empty()) return "";
        
        // Sort the strings alphabetically
        sort(strs.begin(), strs.end());
        
        // Compare the first and last strings
        string first = strs.front();
        string last = strs.back();
        string result = "";
        
        // Find common characters between first and last
        for (int i = 0; i < first.length(); i++) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        
        return result;
    }
};

// optimal approach: vertical scanning

// The vertical scanning approach involves comparing characters of the strings at the same index across all strings. We start from the first character and move downwards, checking if all strings have the same character at that index. If we find a mismatch or reach the end of any string, we stop and return the common prefix found so far. This method has a time complexity of O(n * m), where n is the number of strings and m is the length of the shortest string, and it uses O(1) additional space.


// code for vertical scanning approach
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};