class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> h1(26,0);
        for(int i=0;i<magazine.size();i++){
            h1[magazine[i]-'a']++;
        }

        for(int i=0;i<ransomNote.size();i++){
            h1[ransomNote[i]-'a']--;
            if(h1[ransomNote[i]-'a']<0)
                return false;
        }
        return true;
    }
};