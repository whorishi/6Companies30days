/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto ele:flights)
            graph[ele[0]].push_back({ele[1],ele[2]});
        queue<vector<int>>q;
        k+=1;
        vector<int>Tcost(n,INT_MAX);
        Tcost[src]=0;
        // node , cost , stops
        q.push({src,0,0});
        while(!q.empty())
        {
            auto v = q.front();
            q.pop();
            for(auto ele:graph[v[0]])
            {
                if(v[2]<k && Tcost[ele.first]>v[1]+ele.second)
                {
                    Tcost[ele.first] = v[1]+ele.second;
                    q.push({ele.first,Tcost[ele.first],v[2]+1});
                }
            }
        }
        if(Tcost[dest]==INT_MAX) return -1;
        return Tcost[dest];
    }
};