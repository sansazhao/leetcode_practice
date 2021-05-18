class Solution {
public:
    int myAtoi(string str) {
        long long sum = 0;
        int sign = 1;
        bool valid = true;
        for (int i = 0; i < str.size(); ++i){
            if (str[i] == ' ' && valid)
                continue;
            else if (isalpha(str[i]) && valid) 
                return sum;
            else if (str[i] >= '0' && str[i] <= '9'){
                sum = 10*sum + sign*(str[i]-'0'); 
                valid = false;
            }
            else if (str[i] == '-' && valid){
                sign = -1;
                valid = false;
            }
            else if (str[i] == '+' && valid){
                sign = 1;
                valid = false;
            }
            else
                return sum;
            if (sum > INT_MAX)
                return INT_MAX;
            if (sum < INT_MIN)
                return INT_MIN;
        }
        return sum;
    }
};