class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> ch(26,0);
        for(int i=0;i<brokenLetters.size();i++){
            ch[brokenLetters[i]-'a']=1;
        }
        istringstream ss(text);
        string token;
        int count=0;
        while(ss>>token){
            int flag=0;
            for(int i=0;i<token.size();i++){
                if(ch[token[i]-'a']==1){
                    flag=1;
                }
            }
            if(flag==0)
                count++;
        }
        return count;
    }
};