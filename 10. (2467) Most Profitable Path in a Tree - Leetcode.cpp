/*
There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.

The game goes on as follows:

* Initially, Alice is at node 0 and Bob is at node bob.
* At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
* For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
    **If the gate is already open, no price will be required, nor will there be any cash reward.
    **If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
*If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.


*/


class Solution {
public:
    int ans=INT_MIN;
    int profit=0;
    
    void dfsToCalculateMaxProfit(int i, vector<vector<int>>& tree, vector<int>& vis,vector<int>& amount)
    {
        vis[i]=1;
        profit+=amount[i];
        int trav=0;
        for(auto ele:tree[i])
        {
            if(!vis[ele])
            {
                trav++;
                vis[ele]=1;
                dfsToCalculateMaxProfit(ele,tree,vis,amount);
                vis[ele]=0;
            }
        }
        if(trav==0) ans=max(ans,profit);  //if trav is 0 means this is the leaf node and we update our ans
        profit-=amount[i];
    }
    
    void findParentAndDistance(int i, vector<vector<int>>& tree, unordered_map<int,int>& Parent,unordered_map<int,int>& DistanceFromAlice,int currdis,vector<int>& vis)
    {
        vis[i]=1;
        DistanceFromAlice[i]=currdis;
        for(auto ele:tree[i])
        {
            if(!vis[ele]) {
                Parent[ele]=i;
                findParentAndDistance(ele,tree,Parent,DistanceFromAlice,currdis+1,vis);
            }
        }
        vis[i]=0;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        vector<vector<int>>tree(edges.size()+1);         //construct tree using adjacency list
        for(auto edge:edges)                             //construct tree using adjacency list
        {                                                //construct tree using adjacency list
            tree[edge[0]].push_back(edge[1]);            //construct tree using adjacency list
            tree[edge[1]].push_back(edge[0]);            //construct tree using adjacency list
        }
        
        
        vector<int>vis(edges.size()+1,0);
        unordered_map<int,int>Parent;
        unordered_map<int,int>DistanceFromAlice;
        Parent[0]=0;
        findParentAndDistance(0,tree,Parent,DistanceFromAlice,0,vis);    //Parent,Distance using dfs
        
        int currNode = bob;
        int DisFromBob=0;
        while(currNode!=0)       //updating amount of the common path of alice and bob
        {
            if(DistanceFromAlice[currNode]>DisFromBob)
            {
                amount[currNode]=0;    //for alice no profit is there because bob will open gate first
            }
            else if(DistanceFromAlice[currNode]==DisFromBob)
            {
                amount[currNode]/=2;  //both alice and bob will get 50% amount as they open gate at same time
            }
            currNode = Parent[currNode];
            DisFromBob++;
        }
        for(int i=0;i<vis.size();i++) vis[i]=0;
        dfsToCalculateMaxProfit(0,tree,vis,amount);  //calculating profit for every path from 0 to leaf node
        return ans;
    }
};



//Parent,Distance using dfs
//core Logic
//Find profitabl path using dfs