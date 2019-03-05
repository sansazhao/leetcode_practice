// 0 1 分配 → 背包DP问题
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 0)
            return 0;
        int dp[m+1][n+1];
        for(int i = 0; i < m+1; ++i){
            for(int j = 0; j< n+1; ++j){
                dp[i][j] = 0;
            }
        }
        for(auto word: strs){
            int zeros = 0, ones = 0;
            for(auto c: word){
                if(c == '0')++zeros;
                else
                    ++ones;
            } 
            for(int i = m; i >= zeros; --i){
                for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};