/*
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.
*/

class Solution {
public:
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>Set,vis;
        int ans=0;
        for(auto str:bank)
            Set.insert(str);
        queue<string>q;
        q.push(start);
        vis.insert(start);
        vector<char>genes={'A','C','G','T'};
        while(!q.empty())
        {
            string temp = q.front();
            q.pop();
            
            if(temp==end) return ans;
            
            for(int i=0;i<8;i++)
            {
                char orig = temp[i];
                for(int j=0;j<4;j++)
                {
                    temp[i]=genes[j];
                    if(Set.find(temp)!=Set.end())
                    {
                        if(vis.find(temp)==vis.end())
                        {
                            vis.insert(temp);
                            q.push(temp);
                        }
                    }
                }
                temp[i]=orig;
            }
            ans++;
        }
        return -1;
    }
};