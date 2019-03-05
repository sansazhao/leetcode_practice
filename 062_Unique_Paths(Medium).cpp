class Solution {
public:
    int uniquePaths(int m, int n) {
        int D = m-1;
        int S = m+n-2;          //组合数，C t取r： t!/(t-r)!*r!  S!/(S-D)!*D!
        long long ret = 1;
        for (int i = 1; i <= D; i++) {
            ret = ret * (S - D + i) / i;
        }
        return (int) ret;
    }
};