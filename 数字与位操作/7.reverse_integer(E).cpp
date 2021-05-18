class Solution {
public:
    int reverse(int x) {
        long long first = 0; //overflow
        while (x){
            first = first * 10 + x % 10;
            if (first > INT_MAX ||first < INT_MIN)return 0;
            x /= 10;
        }
        return (int)first;
    }
};