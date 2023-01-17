/*
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>m;
        for(auto code:barcodes)
            m[code]++;
        vector<int>ans;
        int cnt=0;
        priority_queue<pair<int,int>>pq;
        for(auto ele:m)
            pq.push({ele.second,ele.first});
        while(!pq.empty())
        {
            auto a=pq.top();
            pq.pop();
            ans.push_back(a.second);
            if(!pq.empty())
            {
                auto b=pq.top();
                pq.pop();
                ans.push_back(b.second);
                if(b.first>1)
                {
                    pq.push({b.first-1,b.second});
                }
            }
            if(a.first>1)
            {
                pq.push({a.first-1,a.second});
            }
        }
        return ans;
    }
};