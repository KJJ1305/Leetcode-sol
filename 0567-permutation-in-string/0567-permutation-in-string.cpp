class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0;
        int n=s1.size();
        int m=s2.size();

        vector<int> h1(26,0),h2(26,0);

        int count=0;
        for(int i=0;i<n;i++){
            h1[s1[i]-'a']++;
        }

        for(int i=0;i<m;i++){
            h2[s2[i]-'a']++;
            count++;

            if(h2==h1)
                return true;
            if(count==s1.size()){
                h2[s2[i-n+1]-'a']--;
                count--;
            }
        }

        return false;
        
        

    }
};