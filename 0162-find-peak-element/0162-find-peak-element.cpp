class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int st=0,end=nums.size()-1;
        int n=nums.size();
        if(n==1)
            return 0;

        while(st<=end){

            int mid=(st+end)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1]) return mid;
                else return mid+1;
            }
            if(mid==n-1){
                if(nums[mid]>nums[mid-1]) return mid;
                else return mid-1;
            }

            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                return mid;
            }

            if(nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else if(nums[mid]<nums[mid+1]){
                st=mid+1;
            }
        }

        return 0;
        

    }
};