// dfs 递归+记录访问
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dfs(word, i, j, board)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(string s, int x, int y, vector<vector<char>>& board){
        if(s.empty())
            return true;
        if(x<0 || y<0 || x >= board.size() || y >= board[0].size()
         || board[x][y] != s[0]){
            return false;
        }
        char c = board[x][y];
        board[x][y] = '*';
        string ss = s.substr(1);
        bool res = dfs(ss, x, y+1, board) || dfs(ss, x, y-1, board)||
                    dfs(ss, x+1, y, board) || dfs(ss, x-1, y, board);
        board[x][y] = c;
        return res;
    }
};