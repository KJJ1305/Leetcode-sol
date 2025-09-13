class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> v(26,0);
        int maxfv=0,maxfc=0;
        set<char> vow={'a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            if(vow.find(s[i])!=vow.end()){
                v[s[i]-'a']++;
                maxfv=max(maxfv,v[s[i]-'a']);
            }
            else{
                v[s[i]-'a']++;
                maxfc=max(maxfc,v[s[i]-'a']);
            }
        }
        return maxfc+maxfv;
    }
};