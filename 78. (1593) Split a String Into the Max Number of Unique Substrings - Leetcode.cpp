/*
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    int ans;
    set<string>ss;
    void check(int i,string s)
    {
        
        if(i==s.length())
        {
            if(ans<ss.size())
            {
                ans=ss.size();
            }
            return;
        }
        string temp;
        for(int j=i;j<s.length();j++)
        {
            temp+=s[j];
            if(ss.find(temp)==ss.end())
            {
                ss.insert(temp);
                check(j+1,s);
                ss.erase(temp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        check(0,s);
        return ans;
    }
    
};