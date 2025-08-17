class Solution {
private:
    bool rec(unordered_set<string> &dict,int start,vector<int> &dp,string &s){
        
        if(start==s.size())
            return true;

        if(dp[start]!=-1)
            return false;

        for(int i=start;i<s.size();i++){
            if(dict.find(s.substr(start,i-start+1))!=dict.end()){
                if(rec(dict,i+1,dp,s))
                    return dp[start]=true;
            }
        }
        return dp[start]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;

        vector<int> dp(s.size(),-1);
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }

        rec(dict,0,dp,s);
        return dp[0];

    }
};