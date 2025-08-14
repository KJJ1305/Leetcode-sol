class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n=num.size();
        string res="";
        int count=1;
        for(int i=1;i<n;i++){
            if(num[i]==num[i-1]){
                count++;

            }
            else{
                count=1;
            }
            
            if(count==3){
                res=max(res,num.substr(i-2,3));
                count=1;
            }
        }
        return res;
        

    }
};