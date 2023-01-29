/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/

bool cmp(pair<int,string>&a, pair<int,string>&b)
    {
        if(a.first == b.first)
            return a.second<b.second;
        return a.first>b.first;
    }

class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        vector<pair<int,string>> v;
        for(auto ele: m)
        {
            v.push_back({ele.second,ele.first});
        }
        sort(v.begin(),v.end(),cmp);
        words.clear();
        for(int i=0;i<k;i++)
            words.push_back(v[i].second);
        return words;
        
    }
};