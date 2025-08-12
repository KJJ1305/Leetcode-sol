class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> rse(n,-1),lse(n,-1);
        stack<int> s;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty())
                rse[i]=s.top();
            else
                rse[i]=n;
            s.push(i);
        }
        stack<int> s2;
        for(int i=0;i<n;i++){
            while(!s2.empty()&&heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(!s2.empty())
                lse[i]=s2.top();
            else
                lse[i]=-1;
            s2.push(i);
        }

        int globmax=0;
        for(int i=0;i<n;i++){
            globmax=max(globmax,heights[i]*(rse[i]-lse[i]-1));
        }
        return globmax;
    }
};