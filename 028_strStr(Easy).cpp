// 减少变量、循环、循环条件的判断，遍历0 ~ m-n
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        int n = haystack.size();
        int i = 0, flag = 0;
        while (i <= haystack.size() - needle.size()) {
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i+j] != needle[j]) 
                    break;
                if (j == needle.size()-1) 
                    return i;
            }
            i++;
        }
        return -1;
    }
};