/*
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int sum=0;
                v.push_back(grid[i][j]);
                for(int k=1;k<=min(m,n);k++)
                {
                    if(i+k>=0 && i+k<m && i-k>=0 && i-k<m && j+k>=0 && j+k<n && j-k>=0 && j-k<n )
                    {
                        int x=0;
                        if(k>=2)
                        {
                            int a,b,inc;
                            a=i-k;
                            b=j;
                            inc=0;
                            while(inc<=k)
                            {
                                x+=grid[a+inc][b-inc];
                                inc++;
                            }
                            a=i;
                            b=j-k;
                            inc=0;
                            while(inc<=k)
                            {
                                x+=grid[a+inc][b+inc];
                                inc++;
                            }
                            a=i+k;
                            b=j;
                            inc=0;
                            while(inc<=k)
                            {
                                x+=grid[a-inc][b+inc];
                                inc++;
                            }
                            a=i;
                            b=j+k;
                            inc=0;
                            while(inc<=k)
                            {
                                x+=grid[a-inc][b-inc];
                                inc++;
                            }
                            x=x-(grid[i+k][j] + grid[i-k][j] + grid[i][j+k] + grid[i][j-k]);
                        }
                        else
                        {
                            x = grid[i+k][j] + grid[i-k][j] + grid[i][j+k] + grid[i][j-k];
                        }
                        v.push_back(x);
                    }
                    else
                    {
                        break;
                    }
                }
                
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        
        // for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
        
        if(v.size()==0) return v;
        int i=1;
        int ele=1;
        vector<int>ans;
        ans.push_back(v[0]);
        while(i<v.size() && ans.size()<3)
        {
            if(v[i]!=ans.back())
            {
                ans.push_back(v[i]);
                ele++;
            }
            i++;
        }
        return ans;
    }
};