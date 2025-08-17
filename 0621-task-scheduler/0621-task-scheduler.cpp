class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char,int> freq;
         priority_queue<int> pq;

        for(char c:tasks){
            freq[c]++;
        }

        for(auto p:freq){
            pq.push(p.second);
        }
        int time=0;

        while(!pq.empty()){
            int cycle=n+1;
            vector<int> temp;
            while(cycle--&&!pq.empty()){
                int curr=pq.top();
                pq.pop();
                curr--;

                if(curr>0)
                    temp.push_back(curr);
                time=time+1;
            }

            for(int cnt:temp){
                pq.push(cnt);
            }

            if(pq.empty())
                break;

            time+=(cycle+1);
        }
        return time;
    }
};