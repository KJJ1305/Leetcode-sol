class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        unordered_map<int,int> m1;
        int m=0;
        while(n!=0){
            m1[n%10]++;
            n=n/10;
        }

        while(m<=30){
            unordered_map<int,int> m2;
            int num=pow(2,m);
            string ni=to_string(num);
            for(int i=0;i<ni.size();i++){
                m2[ni[i]-'0']++;
            }
            if(m2==m1)
                return true;
            m++;
        }
        
        return false;
        
    }
};