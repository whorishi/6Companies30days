/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
*/


class Solution {
public:
    string longestPrefix(string s) {
        int index=-1;
        long long pph=0,psh=0;
        long long ph=0,sh=0;
        long long p=31;
        long long pow=1;
        if(s.length()==1) return "";
        for(int i=0;i<s.length()-1;i++)
        {
            ph = (( pph * p )%1000000007 + (s[i]-'a' + 1))%1000000007;
            sh =  (psh + ((s[s.length()-i-1]-'a'+ 1) * pow)%1000000007)%1000000007;
            pow=(p*pow)%1000000007;
            pph=ph;
            psh=sh;
            if(ph==sh)
            {
                index=i+1;
            }
        }
        if(index==-1)
            return "";
        return s.substr(0,index);
    }
};