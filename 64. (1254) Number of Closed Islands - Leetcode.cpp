/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

class Solution {
public:
    
    void bfs(int x, int y, vector<vector<int>>& grid)
    {
        grid[x][y]=-1;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            if(i-1>=1 && i-1<grid.size()-1 && j>=1 && j<grid[0].size() && grid[i-1][j]==0)
            {
                q.push({i-1,j});
                grid[i-1][j]=-1;
            }
            if(i+1>=1 && i+1<grid.size()-1 && j>=1 && j<grid[0].size() && grid[i+1][j]==0)
            {
                q.push({i+1,j});
                grid[i+1][j]=-1;
            }
            if(i>=1 && i<grid.size()-1 && j+1>=1 && j+1<grid[0].size() && grid[i][j+1]==0)
            {
                q.push({i,j+1});
                grid[i][j+1]=-1;
            }
            if(i>=1 && i<grid.size()-1 && j-1>=1 && j-1<grid[0].size() && grid[i][j-1]==0)
            {
                q.push({i,j-1});
                grid[i][j-1]=-1;
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0 && (i==0 || j==0 ||  i==grid.size()-1 || j==grid[0].size()-1))
                {
                    bfs(i,j,grid);
                }
            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};