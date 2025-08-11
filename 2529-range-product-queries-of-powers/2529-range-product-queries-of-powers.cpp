class Solution {
private:
    vector<int> tobin(int n){

        //string res;
        vector<int> result;
    
         string res = "";
        while (n > 0) {
        res = char('0' + (n % 2)) + res; // prepend bit
        n /= 2;
        }

        int m=res.size(),ind=0;

        for(int i=m-1;i>=0;i--){
            if(res[i]=='1'){
                int val=pow(2,ind);
                result.push_back(val);
            }
            ind++;
        }

        return result;

    }
public:
    #define MOD 1000000007
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> res=tobin(n);
        vector<int> result;

        for(int i=0;i<queries.size();i++){

            int f1=queries[i][0];
            int f2=queries[i][1];
            long long sum=1;
            while(f1<=f2){
                sum=(sum*res[f1])%MOD;
                f1++;
            }
            result.push_back(sum);
        }

        return result;
    }
};