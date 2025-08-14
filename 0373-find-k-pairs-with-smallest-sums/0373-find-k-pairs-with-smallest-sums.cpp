class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        //priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        set<tuple<int,int,int>> pq;

        pq.insert({nums1[0]+nums2[0],0,0});
        auto iter = pq.begin();
        // set<vector<int>> res;
        vector<vector<int>> res;

        int cnt = 0;
        while(!pq.empty()){
            auto [sum, i, j] = *(iter); 
            
            cnt++;
            res.push_back({nums1[i], nums2[j]});

            if (cnt == k) return res;

            if (i+1 < m) pq.insert({nums1[i+1]+nums2[j],i+1,j});
            if (j+1 < n) pq.insert({nums1[i]+nums2[j+1],i,j+1});
            iter++;
        }

        return res;
    }
};