// class Solution {
// public:
//     string reverseWords(string s) {
//         string output;
//         void( string s, int index){
//             for(int i=index; i<index; i++){

//             }
//         }

//         int left =0;
//         int right = s.size() - 1;
//         while(left < right){
//             while(left<right && isalnum(s[right]) ){
//                 right--;
//             }
//         reversed(s , s.size() - right );
//         right--;
        
//         }
//     }
// };

class Solution {
public:
    string reverseWords(string s) {

        int l = 0;
        int r = 0;
        int n = s.length();

        stack<string> st;
        string word = "";

        while (r < n) {

            while (r < n && s[r] == ' ') {
                r++;
            }

            l = r;

            while (r < n && s[r] != ' ') {
                r++;
            }

            if (l < r) {
                word = s.substr(l, r - l);
                st.push(word);
            }
        }

        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();

            if (!st.empty()) {
                result += " ";
            }
        }

        return result;
    }
};