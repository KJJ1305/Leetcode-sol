class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;  
        if (n >= k + maxPts - 1) return 1.0; 
        vector<double> dp(n+1,0);
        dp[0]=1;
        double sum=dp[0]/maxPts;

        for(int i=1;i<=n;i++){
            dp[i]=sum;
            if(i<k)
                sum=sum+dp[i]/maxPts;
            
            if(i>=maxPts){
                sum=sum-dp[i-maxPts]/maxPts;
            }
        }

        double ans=0;
        for(int i=k;i<=n;i++){
            ans+=dp[i];
        }

        return ans;

    }
};