/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>m(3,0);
        
        int right=0,left=0,cnt=0;
        
        while(right<s.length())
        {
            m[s[right]-'a']++;
            while(m[0]>0 && m[1]>0 && m[2]>0)
            { 
                cnt += s.length() - right;
                m[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};