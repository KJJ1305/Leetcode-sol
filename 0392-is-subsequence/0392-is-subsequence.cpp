class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l=0,r=0;
        int n=t.size();
        while(r<n){
            if(l==s.size())
                return true;

            if(s[l]==t[r])
                l++;
            r++;
        }

        if(l==s.size())
            return true;
        else
            return false;
    }
};