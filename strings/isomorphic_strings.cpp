// approch : Using two unordered maps to store the last occurrence of each character in both strings and comparing their positions.


// time complexity: O(n) where n is the length of the strings
// space complexity: O(n) for the unordered maps

// example: s1 = "egg", s2 = "add" => true, s1 = "foo", s2 = "bar" => false, s1 = "paper", s2 = "title" => true
// example: s1 = "ab", s2 = "aa" => false, s1 = "abc", s2 = "def" => true

// example: s1 = "abca", s2 = "zbxz" => true, s1 = "abca", s2 = "zbxy" => false


// approach : the idea is to use two unordered maps to store the last occurrence of each character in both strings and compare their positions. If the positions of the characters in both strings are not the same, then the strings are not isomorphic.



#include <bits/stdc++.h>
class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
    unordered_map<char, int> m1, m2;

    for (int i = 0; i < s1.length(); ++i) {
        
        if (m1.find(s1[i]) == m1.end()) {
            m1[s1[i]] = i;
        }
        if (m2.find(s2[i]) == m2.end()) {
            m2[s2[i]] = i;
        }

        if (m1[s1[i]] != m2[s2[i]]) {
            return false;
        }
    }
    return true;
}
};