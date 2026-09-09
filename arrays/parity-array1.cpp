// approch for this question 

//Construct Uniform Parity Array I

//code 
// Check if all elements in the array have the same parity (all even or all odd)
// If they do, return true; otherwise, return false

// example:
// Input: nums1 = [2, 4, 6, 8]
// Output: true (all elements are even)

// Input: nums1 = [1, 3, 5, 7]
// Output: true (all elements are odd)
// Input: nums1 = [2, 3, 4, 5]
// Output: false (mixed parity)


class Solution {
    public boolean uniformArray(int[] nums1) {
        return true;
    }
}


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n = arr.size();
        int l=0;
        int r = n-1;
        if(n==1){
            return arr;
        }
        while(l<r){
            if (arr[l] % 2 == 1 && arr[r] % 2 == 0){
                swap(arr[r],arr[l]);
                l++;
                r--;
            }
            if (arr[l] % 2 == 0) {
                l++;
            }
            if (arr[r] % 2 == 1) {
                r--;
            }
        }
    return arr;
    }
};