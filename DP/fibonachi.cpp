// this is a C++ program to generate the Fibonacci series using dynamic programming (memoization) approach. The program defines a recursive function `fib` that calculates the Fibonacci number for a given index `n`, while storing previously computed values in a vector `dp` to avoid redundant calculations. The main function prompts the user for input and prints the Fibonacci series up to the specified number of terms.

// by using the memoization technique, the time complexity of the Fibonacci calculation is reduced from exponential O(2^n) to linear O(n), making it efficient for larger values of `n`. The program also handles edge cases where the input is less than or equal to zero by returning early without performing any calculations.



#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    vector<int> dp(n, -1);

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i, dp) << " ";
    }

    return 0;
}
 