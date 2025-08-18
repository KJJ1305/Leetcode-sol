class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totsum=0,maxval=0;
        int n=weights.size();

        for(int i=0;i<n;i++){
            totsum+=weights[i];
            maxval=max(weights[i],maxval);
        }

        int st=maxval,end=totsum;
        int mid;
        int posval=INT_MAX;
        while(st<=end){
            mid=(st+end)/2;
            int d=1;
            int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+weights[i];
                if(sum>mid){
                    sum=weights[i];
                    d++;
                }
            }
            if(d<=days){
                posval=min(mid,posval);
                end=mid-1;
            }
            else if(d>days){
                st=mid+1;
            }
        }

        return posval;

    }
};