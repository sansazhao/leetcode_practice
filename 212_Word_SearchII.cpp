class Solution {
public:
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.size() == 0)return res;
        m = board.size();
        n = board[0].size();
        sort(words.begin(),words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        for(int k = 0; k < words.size(); ++k){
            if(exist(board, words[k]))
                res.push_back(words[k]);
        }
        return res;
    }
    
     bool exist(vector<vector<char>>& board, string word) {
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
        if(x<0 || y<0 || x >= m || y >= n || board[x][y] != s[0]){
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