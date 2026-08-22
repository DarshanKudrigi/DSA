// approch first we will find the sum and product of the digits of the number n. then we will add the sum and product and check if n is divisible by the total or not. if it is divisible then we will return true else false.

// problem number: 3622

// example 1:
// Input: n = 12
// Output: true

// example 2:
// Input: n = 101   
// Output: false

// time complexity: O(d) where d is the number of digits in n.
// space complexity: O(1) as we are using constant space.

// problem link: https://leetcode.com/problems/check-if-a-number-is-divisible-by-sum-of-its-digits-and-product-of-its-digits/

// code for checking divisibility of a number by the sum and product of its digits

// The function checkDivisibility takes an integer n as input and returns a boolean indicating whether n is divisible by the sum and product of its digits. It calculates the sum and product of the digits of n, adds them together, and checks if n is divisible by this total. If it is, the function returns true; otherwise, it returns false.

// difficulty level: Easy
// tags: math, number theory, digit manipulation, divisibility



class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }
        
        int total = sum + product;
        
        return (n % total == 0); 
    }
};
