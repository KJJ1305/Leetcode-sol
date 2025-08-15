class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> h1(26,0),h2(26,0);
        vector<int> res;
        int k=p.size();

        for(int i=0;i<p.size();i++){
            h1[p[i]-'a']++;
        }
        int count=0;

        for(int i=0;i<s.size();i++){
            h2[s[i]-'a']++;
            count++;

            if(h2==h1)
                res.push_back(i-k+1);

            if(count==k){
                h2[s[i-k+1]-'a']--;
                count--;
            }
        }
        return res;
    }
};