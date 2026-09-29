// permutation in String

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

// Question Link: https://leetcode.com/problems/permutation-in-string/



// Approach 1: Brute Force

// In this approach, we generate all the permutations of s1 and check if any of them is a substring of s2. If we find a match, we return true. If we finish checking all permutations and find no match, we return false. This approach has a time complexity of O(n! * m), where n is the length of s1 and m is the length of s2.


// Approach 2: Sliding Window
// In this approach, we use a sliding window of size equal to the length of s1 to check if any substring of s2 is a permutation of s1. We maintain a frequency count of characters in s1 and the current window in s2. If the frequency counts match, we return true. If we finish checking all windows and find no match, we return false. This approach has a time complexity of O(m), where m is the length of s2.



// time complexity: O(n + m), where n is the length of s1 and m is the length of s2.

// space complexity: O(1), as we are using a fixed size array of 26 to store the frequency counts of characters.



// Approach 3: Sliding Window with Two Pointers
// In this approach, we use two pointers to maintain a sliding window of size equal to the





class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1)
            freq1[c - 'a']++;

        for (int i = 0; i < n; i++)
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2)
            return true;

        for (int r = n; r < m; r++) {
            freq2[s2[r] - 'a']++;
            freq2[s2[r - n] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};