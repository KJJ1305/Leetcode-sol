class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<pair<string,int>> q;
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        q.push({"0000",0});
        while(!q.empty()){
            auto [s,val]=q.front();
            q.pop();

            if(s==target)
                return val;

            if(dead.find(s)!=dead.end())
                continue;

            for(int i=0;i<4;i++){
                char temp = s[i];

                s[i] = (temp == '0' ? '9' : temp - 1);
                if (!vis.count(s)) {
                    vis.insert(s);
                    q.push({s, val + 1});
                }

                s[i] = (temp == '9' ? '0' : temp + 1);
                if (!vis.count(s)) {
                    vis.insert(s);
                    q.push({s, val + 1});
                }

                s[i] = temp;
            }   
        }

        return -1;
    }
};