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


//by using the tabulation technique, the time complexity of the Fibonacci calculation is also linear O(n), and it avoids the overhead of recursive function calls. The program initializes a vector `dp` to store Fibonacci numbers iteratively, starting from the base cases, and builds up to the desired index `n`. This approach is efficient and straightforward for generating the Fibonacci series.

// tc- O(n)
// sc- O(n)

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    if(n <= 0){
        return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci Series: ";
    for(int i = 0; i < n; i++){
        cout << dp[i] << " ";
    }

    return 0;
}


// // removing the extra space and making the code more readable, the program can be structured as follows:
// by using the space optimization technique, the time complexity of the Fibonacci calculation remains linear O(n), but the space complexity is reduced to O(1) by only keeping track of the last two Fibonacci numbers instead of storing the entire series. This approach is efficient and suitable for generating Fibonacci numbers without using additional memory for storage.



int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    if(n <= 0){
        return 0;
    }

    int prev2 = 0;
    int prev1 = 1;

    cout << "Fibonacci Series: " << prev2 << " " << prev1 << " ";

    for(int i = 2; i < n; i++){
        int curr = prev1 + prev2;
        cout << curr << " ";
        prev2 = prev1;
        prev1 = curr;
    }

    return 0;
}