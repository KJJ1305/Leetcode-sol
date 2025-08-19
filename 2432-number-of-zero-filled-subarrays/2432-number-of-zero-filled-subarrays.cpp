class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0;
        long long totoccur=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                totoccur+=(c*(c+1)/2);
                c=0;
            }
            else if(nums[i]==0)
                c++;
        }
        totoccur+=(c*(c+1)/2);
        return totoccur;

    }
};