//仅限[-2^31,2^31-1], 区分了正负情况 略繁琐
//边界情况多
//位操作
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN && divisor != dividend) return 0;
        if (divisor == dividend) return 1;
        int sign = (dividend >> 31 ^ divisor >> 31) ? -1 : 1;
        int b = abs(divisor);
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MAX && b == 1) return INT_MAX*sign;
        int ans = 0;
        int a = dividend;
        int tmp, i;
        if (a >= 0) {
            while (a >= b) {
                tmp = b, i = 1;
                while (tmp < INT_MAX>>1 && a >= tmp << 1) {
                    tmp <<= 1;
                    i <<= 1;
                }
                a -= tmp;
                ans += i;
            }
        }
        else {        
            while (a <= -b) {
                tmp = b, i = 1;
                while (tmp < (INT_MAX>>1) && a <= -(tmp << 1)) {
                    tmp <<= 1;
                    i <<= 1;
                }
                a += tmp;
                ans += i;
            } 
        }
        return sign * ans;
    }
};