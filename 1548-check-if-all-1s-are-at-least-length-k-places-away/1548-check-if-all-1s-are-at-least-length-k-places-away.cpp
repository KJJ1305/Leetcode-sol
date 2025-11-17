class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=0;
        int flag=0;
        int j;
        for(j=0;j<nums.size();j++){
            if(nums[j]==1)
                break;
        }
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]==1){
                if(count<k)
                    return false;
                count=0;
                continue;
            }
            count++;
        }

        return true;
    }
};