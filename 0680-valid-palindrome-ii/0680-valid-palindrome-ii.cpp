class Solution {
private:
    bool rec(string s,int l,int r,int flag){

        while(l<=r){
            if(s[l]!=s[r]){
                if(flag==1)
                    return false;
                else
                    return rec(s,l+1,r,1)||rec(s,l,r-1,1);
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return rec(s,0,s.size()-1,0);
    }
};