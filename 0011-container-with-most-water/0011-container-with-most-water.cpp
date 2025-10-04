class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        
        int result=0;
        while(l<r){
            int less=min(height[l],height[r]);
            int water=less*(r-l);
                result=max(result,water);
            if(height[l]<=height[r])
                l++;
            else
                r--;
        }
        return result;
    }
};