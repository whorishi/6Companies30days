/*
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>m,li;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            m[cards[i]]++;
            if(m[cards[i]]>=2)
            {
                if((i-li[cards[i]]+1) < ans)
                {
                    ans=i-li[cards[i]]+1;
                }
            }
            li[cards[i]]=i;
        }
        if(ans==INT_MAX)  return -1;
            return ans;
    }
};

