/*
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

*The number of "bulls", which are digits in the guess that are in the correct position.
*The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
*/



class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.size()!=guess.size()) return "0A0B";
        unordered_map<char,int>m1,m2;
        int cows=0,bulls=0;
        
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        
        for(auto ele:m1)
        {
            cows+= min(m1[ele.first],m2[ele.first]);
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};