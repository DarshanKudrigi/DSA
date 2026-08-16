// 680. Valid Palindrome II
// approch: check if the string is palindrome, if not, try deleting every character and check if the resulting string is palindrome
// Time complexity: O(n^2)
// Space complexity: O(n)



// Note: This solution can be optimized to O(n) time complexity and O(1) space complexity by using two pointers and checking for palindrome while skipping at most one character.



class Solution {
public:

    // Check whether string is palindrome
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        if (isPalindrome(s)) {
            return true;
        }

        // Try deleting every character
        for (int i = 0; i < s.length(); i++) {

            string temp = "";

            // Create a new string without s[i]
            for (int j = 0; j < s.length(); j++) {

                if (j != i) {
                    temp += s[j];
                }
            }

            // Check if resulting string is palindrome
            if (isPalindrome(temp)) {
                return true;
            }
        }

        return false;
    }
};



// optimized solution

// 680. Valid Palindrome II
// approch: check if the string is palindrome, if not, try deleting either the left
// or the right character and check if the resulting string is palindrome
// Time complexity: O(n)
// Space complexity: O(1)




// the solution uses two pointers to check for palindrome while skipping at most one character.

class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try deleting either the left or the right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};