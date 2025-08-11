class Solution {
private:
    bool ispalindrome(string s){

        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrac(int ind,string &s,vector<string> &res,vector<vector<string>> &ans){

        if(ind==s.size()){
            ans.push_back(res);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s.substr(ind,i-ind+1))){
                res.push_back(s.substr(ind,i-ind+1));
                backtrac(i+1,s,res,ans);
                res.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> ans;
        backtrac(0,s,res,ans);
        return ans;
    }
};