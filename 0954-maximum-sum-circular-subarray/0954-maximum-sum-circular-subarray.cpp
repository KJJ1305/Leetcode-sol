class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for(auto val:nums){
            totalSum+=val;
            currMax=max(val,currMax+val);
            maxSum=max(maxSum,currMax);

            currMin=min(val,currMin+val);
            minSum=min(minSum,currMin);
        }
        if(totalSum==minSum)
            return maxSum;

        return max(maxSum,totalSum-minSum);
    }
};