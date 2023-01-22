/*
Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.

You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.

Return the maximum number of consecutive floors without a special floor.
*/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        //sort the special array
        sort(special.begin(),special.end());
        //starting difference
        int first = special[0]-bottom;
        //ending difference
        int last = top - special[special.size()-1];
        //finding max difference
        int ans = max(first,last);
        //finding differences between the sentinals
        for(int i=1;i<special.size();i++)
        {
            ans= max(ans,special[i]-special[i-1]-1);
        }
        return ans;
    }
};