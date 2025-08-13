class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int l=0,r=0;
        int n=nums.size();
        int globmax=INT_MAX,sum=0;

        while(r<n){
            sum=sum+nums[r];
            while(sum>=target){
                globmax=min(globmax,r-l+1);
                sum=sum-nums[l];
                l++;
            }
            r++;
        }
        return globmax==INT_MAX?0:globmax;
    }
};