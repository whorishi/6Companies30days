/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.*/


bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        return a.second<b.second;
    }

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vp;
        for(int i=0;i<capital.size();i++)
        {
            vp.push_back({profits[i],capital[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        priority_queue<pair<int,int>>pq;
        int j=0;
        while(k--)
        {
            while(j<vp.size() && vp[j].second<=w)
            {
                pq.push(vp[j++]);
            }
            if(pq.empty())
            {
                break;
            }
            w+=pq.top().first;
            pq.pop();
        }
        return w;
    }
};