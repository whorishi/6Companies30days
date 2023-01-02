/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int, int>>> graph(n);
        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> distance(n, LONG_MAX);
        vector<int> path(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()) {
            pair<long long, int> t = pq.top();
            pq.pop();
            
            for(auto &nbr: graph[t.second]) {
                long long vert = nbr.first;
                long long edge = nbr.second;
                
                if(distance[vert] > distance[t.second] + edge) {
                    distance[vert] = distance[t.second] + edge;
                    pq.push({distance[vert], vert});
                    path[vert] = path[t.second] %mod;
                }
                else if(distance[vert] == t.first + edge) {
                    path[vert] += path[t.second];
                    path[vert] %= mod;
                }
            }
        }
        
        return path[n-1];
    }
};