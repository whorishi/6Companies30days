/*
You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.

The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.

If multiple creators have the highest popularity, find all of them.
If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.
*/

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,pair<string,pair<long long,long long>>> m;
        for(int i=0;i<creators.size();i++)
        {
            m[creators[i]].second.first+=views[i];
            if(m[creators[i]].second.second<views[i])
            {
                m[creators[i]].second.second=views[i];
                m[creators[i]].first=ids[i];
            }
            else if(m[creators[i]].second.second==views[i])
            {
                if(m[creators[i]].first=="" || m[creators[i]].first>ids[i])
                {
                    m[creators[i]].first=ids[i];
                }
            }
        }
        
        long long max=0;
        for(auto i:m)
        {
            if(i.second.second.first>max)
                max=i.second.second.first;
        }
        vector<vector<string>> ans;
        for(auto i:m)
        {
            if(i.second.second.first==max)
                ans.push_back({i.first,i.second.first});
        }
        return ans;
    }
};