/*
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
*/

class Solution {
public:

    bool hasAllCodes(string s, int k) {
        if(s.length()<k)
            return false;
        unordered_map<string,int>ss;
        for(int i=0;i<s.length()-k+1;i++)
        {
            ss[s.substr(i,k)]=1;
        }
        return ss.size()==pow(2,k);
    }
};