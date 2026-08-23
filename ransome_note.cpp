// approach : Hashing           

//probelm statement : Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise. Each letter in magazine can only be used once in ransomNote.

// example 1 :
// Input: ransomNote = "a", magazine = "b"
// Output: false

//example 2 :
// Input: ransomNote = "aa", magazine = "ab"
// Output: false


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int RN = ransomNote.size(); 
        int MG = magazine.size();
        unordered_map<char,int> mpp;
        for( int i=0;i<MG;i++ ){
            mpp[magazine[i]]++;
        }
        for( int i=0; i<RN; i++ ){
            mpp[ransomNote[i]]--;
            if(mpp[ransomNote[i]]<0){
                return false;
            }
        }
        return true;
    }
};