/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/
class Solution {
public:
    void bfs(int i, vector<vector<pair<int,int>>>& graph, vector<int>& time, vector<bool>& vis)
    {
        vis[i]=true;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,i});
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int currtime = x.first;
            for(auto ele:graph[x.second])
            {
                if(!vis[ele.first])
                {
                    if(time[ele.first] > currtime + ele.second)
                    {
                        time[ele.first] = currtime+ele.second;
                        pq.push({time[ele.first],ele.first});
                    }
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto time:times)
            graph[time[0]].push_back({time[1],time[2]});
        vector<bool>vis(n+1,false);
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        bfs(k,graph,time,vis);
        int ans=INT_MIN;
        for(int i=1;i<time.size();i++)
        {
            ans=max(time[i],ans);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
    
};