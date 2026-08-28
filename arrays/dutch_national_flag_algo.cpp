// sort colors in the order of red, white and blue
// Dutch National Flag Algorithm

// problem statement: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.


// approch: Dutch National Flag Algorithm

// time complexity: O(n) where n is the length of the array
// space complexity: O(1) as we are not using any extra space


// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     void sortColors(std::vector<int>& arr) {
//         int low = 0;
//         int mid = 0;
//         int high = arr.size() - 1;

//         while (mid <= high) {
//             if (arr[mid] == 0) {
//                 swap(arr[low], arr[mid]);
//                 low++;
//                 mid++;
//             } 
//             else if (arr[mid] == 1) {
//                 mid++;
//             } 
//             else { 
//                 swap(arr[mid], arr[high]);
//                 high--;
//             }
//         }
//     }
// };
 


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void sortColors(vector<int>& arr) {
    int n = arr.size();
    int low = 0, mid =0, high= n-1; 
    while(mid <= high) {
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
};

