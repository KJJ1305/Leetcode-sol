class Solution {
public:
    string minWindow(string s, string t) {
        
        int len=INT_MAX,sindex=-1,count=0;
        int n=s.size(),m=t.size();
        int l=0,r=0;
        vector<int> hash(256,0);

        count=m;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){
            if(hash[s[r]]>0){
                count--;
            }
            hash[s[r]]--;
            r++;

            while(count==0){
                if(r-l<len){
                    len=r-l;
                    sindex=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count++;
                }
                l++;
            }

        }

        return sindex==-1? "":s.substr(sindex,len);
    }
};