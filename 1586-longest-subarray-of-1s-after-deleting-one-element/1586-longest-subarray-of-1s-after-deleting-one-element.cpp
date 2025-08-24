class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int rescunt=0;
        int n=nums.size();
        int k=0;
        while(r<n){

            if(nums[r]==0&&k==0){
                k=1;
            }
            else if(nums[r]==0&&k==1){
                while(nums[l]!=0){
                    l++;
                }
                l++;
            }
            rescunt=max(rescunt,r-l+1);
            cout<<rescunt<<endl;
            r++;
        }
        return rescunt-1;
    }
};