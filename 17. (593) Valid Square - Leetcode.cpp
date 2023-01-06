/*
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).
*/

class Solution {
public:
    int dis(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<int>s;
        
        s.insert(dis(p1,p2));
        s.insert(dis(p1,p3));
        s.insert(dis(p1,p4));
        s.insert(dis(p2,p3));
        s.insert(dis(p2,p4));
        s.insert(dis(p3,p4));
        
        return !s.count(0) && s.size()==2;
        
    }
};