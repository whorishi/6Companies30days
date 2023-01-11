/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        int n=abs(numerator),d=abs(denominator);
        string ans;
        long long q=n/d;
        long long r=n%d;
        ans+=to_string(q);
        if(r==0)
        {
            if(numerator<0 && denominator<0 || numerator>0 && denominator>0)
                return ans;
            if(numerator<0 && denominator>0 || numerator>0 && denominator<0)
                return "-"+ans;
        }
        else
        {
            ans+='.';
            unordered_map<int,int>m;
            while(r!=0)
            {
                if(m.find(r)!=m.end())
                {
                    int i=m[r];
                    ans.insert(i,"(");
                    ans+=')';
                    break;
                }
                else
                {
                    m[r]=ans.length();
                    r=r*10;
                    q=r/d;
                    r=r%d;
                    ans+=to_string(q);
                }
            }
        }
        if(numerator<0 && denominator<0 || numerator>0 && denominator>0)
                return ans;
        else
                return "-"+ans;
    }
};