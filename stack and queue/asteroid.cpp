// Problem: Asteroid Collision

// Difficulty: Medium

// Solution: The problem can be solved using a stack data structure. We will iterate through the list of asteroids and use the stack to keep track of the asteroids that are still in motion. When we encounter a left-moving asteroid, we will check the top of the stack to see if there is a right-moving asteroid that it can collide with. If there is, we will compare their sizes and determine which one will survive. If the left-moving asteroid is larger, it will destroy the right-moving asteroid and continue moving. If they are the same size, both will be destroyed. If the right-moving asteroid is larger, it will remain in the stack and the left-moving asteroid will be destroyed. We will continue this process until we have processed all asteroids.


// C++ language standard version: This project uses the C++17 language standard version.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to determine the state of 
    asteroids after all collisions */
    vector<int> asteroidCollision(vector<int> &asteroids){
        
        // Size of the array
        int n = asteroids.size();
        
        // List implementation of stack
        vector<int> st;  
        
        // Traverse all the asteroids
        for(int i=0; i < n; i++) {
            
            /* Push the asteroid in stack if a 
            right moving asteroid is seen */
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            
            /* Else if the asteroid is moving 
            right, perform the collisions */
            else {
                
                /* Until the right moving asteroids are 
                smaller in size, keep on destroying them */ 
                while(!st.empty() && st.back() > 0 && 
                    st.back() < abs(asteroids[i])) {
                    
                    // Destroy the asteroid
                    st.pop_back();
                }
                
                /* If there is right moving asteroid 
                which is of same size */
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    
                    // Destroy both the asteroids
                    st.pop_back();
                }
                
                /* Otherwise, if there is no left
                moving asteroid, the right moving 
                asteroid will not be destroyed */
                else if(st.empty() ||
                        st.back() < 0){
                    
                    // Storing the array in final state
                    st.push_back(asteroids[i]);
                }
            }
        }
        
        // Return the final state of asteroids
        return st;
    }
};

int main() {
    vector<int> arr = {10, 20, -10};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine the state of 
    asteroids after all collisions */
    vector<int> ans = sol.asteroidCollision(arr);
    
    cout << "The state of asteroids after collisions is: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}


// Amazon
// Meta
// Uber
// Lyft
// JPMorgan Chase

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to determine the state of 
    asteroids after all collisions */
    vector<int> asteroidCollision(vector<int> &asteroids){
        
        int n = asteroids.size();
        stack<int> st;  
        
        for(int i=0; i < n; i++) {
            
            /* Push the asteroid in stack if a 
            right-moving (> 0) asteroid is seen */
            if(asteroids[i] > 0) {
                st.push(asteroids[i]); // FIX: Changed 'Push' to 'push'
            }
            
            /* Else if the asteroid is moving left (< 0), 
            perform the collisions */
            else {
                
                /* Until the right-moving asteroids are 
                smaller in size, keep on destroying them */ 
                while(!st.empty() && st.top() > 0 && 
                      st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                
                /* If there is a right-moving asteroid 
                which is of the exact same size */
                if(!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                }
                
                /* Otherwise, if the stack is empty OR the top 
                asteroid is also moving left, no collision happens */
                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]); // FIX: Changed 'Push' to 'push'
                }
            }
        }
        
        // FIX: Convert stack to vector since function returns vector<int>
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};

int main() {
    vector<int> arr = {10, 20, -10};
    
    Solution sol; 
    vector<int> ans = sol.asteroidCollision(arr);
    
    cout << "The state of asteroids after collisions is: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
