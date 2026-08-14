// C++ program to implement a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//time complexity: O(1) for all operations

//space complexity: O(n) for the stack and O(n) for the min stack

// approach: use two stacks, one for the actual stack and one for the minimum values. When pushing a new value, compare it with the current minimum and push the smaller value onto the min stack. When popping, pop from both stacks. The top of the min stack will always be the minimum value in the main stack.



// #include <bits/stdc++.h>

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public: 
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int val) {
        st.push(val);

        if (minSt.empty()) {
            minSt.push(val);
        } 
        else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {

    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum: " << minStack.getMin() << endl;

    minStack.pop();

    cout << "Top: " << minStack.top() << endl;
    cout << "Minimum: " << minStack.getMin() << endl;

    return 0;
}





// approach 2: using a single stack to store pairs of (value, current minimum). This way, we can keep track of the minimum value at each level of the stack without needing a separate min stack. When pushing a new value, we compare it with the current minimum and store the smaller value as the new minimum. When popping, we simply pop the top pair from the stack. The top of the stack will always contain the current value and its corresponding minimum.

// time complexity: O(1) for all operations
// space complexity: O(n) for the stack

#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack <pair<int,int>> st;
public:
    MinStack() {
    }
    void push(int value) {
        
        if(st.empty()) {
            st.push( {value, value} );
            return;
        }
        else{
            int mini = st.top().second; 
            mini = min(mini, value);
            st.push({value, mini});
        }
    }
    void pop() {
        st.pop(); 
    }

    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack s;
    
    
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}