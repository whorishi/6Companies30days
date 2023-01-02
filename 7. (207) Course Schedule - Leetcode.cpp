/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 
Return true if you can finish all courses. Otherwise, return false.
*/

class Solution {
public:
    
    bool checkcycle(int i, vector<vector<int>>&g, vector<int>&vis, vector<int>&dfsvis)
    {
        vis[i]=1;
        dfsvis[i]=1;
        for(auto ele:g[i])
        {
            if(!vis[ele])
            {
                if(checkcycle(ele,g,vis,dfsvis)) return true;
            }
            else if(dfsvis[ele])
                return true;
        }
        dfsvis[i]=0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>g(n);
        for(int i=0;i<pre.size();i++)
        {
            g[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,g,vis,dfsvis)) return false;
            }
        }
        return true;
    }
};