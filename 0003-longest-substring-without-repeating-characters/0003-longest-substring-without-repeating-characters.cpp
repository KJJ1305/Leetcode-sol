class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        int l=0,r=0;
        int maxlength=0;
        while(r<n){
            for(int i=r-1;i>=l;i--){
                if(s[i]==s[r]){
                    l=i+1;
                    break;
                }
            }
            maxlength=max(maxlength,r-l+1);
            r++;
        }
        return maxlength;
    }
};