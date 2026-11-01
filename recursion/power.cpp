// Calculate the power of a number using while loop and exponentiation by squaring method. The program defines a class `Power` with a method `pwr` that takes a base `x` and an exponent `p`, and calculates `x` raised to the power of `p`. The method handles negative exponents by taking the reciprocal of the base and converting the exponent to positive. The main function prompts the user for input and prints the result of the power calculation.


// The time complexity of the power calculation using exponentiation by squaring is O(log p), making it efficient for large values of `p`. The space complexity is O(1) since the calculation is done iteratively without using additional data structures.



#include <iostream>
using namespace std;

class Power {
    public:
        float pwr(double x, int p){
                long long exp = p;
                if(exp < 0){
                    x = 1/x;
                    exp = -exp;
                }
                int ans =1;
                while(exp>0){
                    if(exp%2==1){
                        ans *= x;
                    }
                    x *= x;
                    exp /= 2;
                }
                return ans;
        }
};

int main(){
    double x;
    int p;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (p): ";
    cin >> p;

    Power powerCalculator = Power();
    float result = powerCalculator.pwr(x, p);
    cout << x << " raised to the power of " << p << " is: " << result << endl;

    return 0;
}









// Calculate the power of a number using recursion and exponentiation by squaring method. The program defines a class `Power2` with a method `pwr` that takes a base `x` and an exponent `p`, and calculates `x` raised to the power of `p`. The method handles negative exponents by taking the reciprocal of the base and converting the exponent to positive. The recursive helper function `pwrHelper` performs the actual calculation using the exponentiation by squaring technique.


// The time complexity of the power calculation using recursion and exponentiation by squaring is O(log p), making it efficient for large values of `p`. The space complexity is O(log p) due to the recursive function call stack.

// The main function prompts the user for input and prints the result of the power calculation.


class Power2{
    public:
        float pwr(double x, int p){
                long long exp = p;
                if(exp < 0){
                    x = 1/x;
                    exp = -exp;
                }
                int ans =1; 
                return pwrHelper(x, exp,ans);
        }
    public:
        float pwrHelper(double x, long long exp, int ans){
            if(exp == 0){
                return ans;
            }
            if(exp % 2 == 1){
                ans *= x;
            }
            x *= x;
            exp /= 2;
            return pwrHelper(x, exp, ans);
        }
};

