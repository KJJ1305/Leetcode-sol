class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
        //ROW
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(s.find(board[i][j])!=s.end())
                    return false;
                else if(board[i][j]!='.'){
                    s.insert(board[i][j]);
                }
            }
        }

        //COL
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(s.find(board[j][i])!=s.end())
                    return false;
                else if(board[j][i]!='.'){
                    s.insert(board[j][i]);
                }
            }
        }
        vector<pair<int,int>> starts={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

        for(auto p:starts){
            set<char> s;
            for(int i=p.first;i<p.first+3;i++){
                for(int j=p.second;j<p.second+3;j++){
                    if(s.find(board[i][j])!=s.end())
                        return false;
                    else if(board[i][j]!='.'){
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};