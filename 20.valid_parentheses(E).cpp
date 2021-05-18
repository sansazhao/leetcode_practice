// 数据结构：栈
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char &c: s){
            switch(c){
                case '{':case '[': case '(':
                    sta.push(c);
                    break;
                case '}':
                    if(sta.size() == 0 || sta.top() != '{')
                        return false;
                    else
                        sta.pop();
                    break;
                case ']':
                    if(sta.size() == 0 || sta.top() != '[')
                        return false;
                    else
                        sta.pop();
                    break;
                case ')':
                    if(sta.size() == 0 || sta.top() != '(')
                        return false;
                    else
                        sta.pop();
                    break;
            }
        }
        return sta.empty();
    }
};