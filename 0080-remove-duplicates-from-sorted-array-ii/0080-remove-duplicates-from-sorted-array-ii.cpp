class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int l=1,r=1;
        int n=nums.size();
        int count=1;
        if(n==1)
            return 1;
        while(r<n){
            if(nums[r]==nums[r-1]){
                if(count==2){
                while(r<n&&nums[r]==nums[r-1])
                    r++;
                count=1;
                }
                else
                    count++;
            }
            else
                count=1;
            if(r==n)
                break;

            nums[l]=nums[r];
            r++;
            l++;
        }
        return l;
    }
};