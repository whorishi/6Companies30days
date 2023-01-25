/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/

class Solution {
public:
    vector<string> ans;
    
    bool isvalid(string str)
    {
        if(str[0]=='0')
            return false;
        return stoi(str)<=255;
    }
    
    void solve(int i, string s, string temp, int par)
    {
        if(i==s.length() || par==4)
        {
            if(i==s.length() && par==4)
                ans.push_back(temp.substr(0,temp.length()-1));
            return;
        }
        
        solve(i+1,s,temp+s[i]+".",par+1);
        if(i+2<=s.length() && isvalid(s.substr(i,2)))
            solve(i+2,s,temp+s.substr(i,2)+".",par+1);
        if(i+3<=s.length() && isvalid(s.substr(i,3)))
            solve(i+3,s,temp+s.substr(i,3)+".",par+1);
    }
    
    vector<string> restoreIpAddresses(string s) {
        string temp;
        solve(0,s,temp,0);
        return ans;
    }
};