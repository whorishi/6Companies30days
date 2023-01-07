/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.
*/

class Solution {
public:
    int dis(int x1,int y1,int x2,int y2)
    {
        return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int>m;
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    m[dis(points[i][0],points[i][1],points[j][0],points[j][1])]++;
                }
            }
            for(auto ele:m)
            {
                cnt+=ele.second*(ele.second-1);
            }
            m.clear();
        }
        
        return cnt;
    }
};
