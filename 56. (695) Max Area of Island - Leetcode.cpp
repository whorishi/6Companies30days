/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
public:
    
    int maxArea=0;
    int m,n;
    
    bool isvalid(int x,int y, vector<vector<int>>& grid) {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1) return true;
        return false;
    }

    void bfs(int i,int j, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    {
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        int cnt=1;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(isvalid(x+1,y,grid) && !vis[x+1][y]) {
                cnt++;
                q.push({x+1,y});
                vis[x+1][y]=true;
            }
            if(isvalid(x-1,y,grid) && !vis[x-1][y]){
                cnt++;
                q.push({x-1,y});
                vis[x-1][y]=true;
            }
            if(isvalid(x,y+1,grid) && !vis[x][y+1]){
                cnt++;
                q.push({x,y+1});
                vis[x][y+1]=true;
            }
            if(isvalid(x,y-1,grid) && !vis[x][y-1]){
                cnt++;
                q.push({x,y-1});
                vis[x][y-1]=true;
            }
        }
        maxArea=max(maxArea,cnt);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                    bfs(i,j,grid,vis);
            }
        }
        return maxArea;
    }
};