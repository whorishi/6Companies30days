/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int zero=0;
        for(int i=5;n/i>0;i=i*5)
        {
            zero+=n/i;
        }
        return zero;
    }
};