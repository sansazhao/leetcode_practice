#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

string mostAppearSubstring(string str){
    string res = "";
    char times[26] = {0};
    for(int i = 0; i<str.length(); ++i){
        ++times[str[i] - 'a'];
    }
    int most_time = 0;
    map<char, int> most_ch;
    for(int i = 0; i < 26; ++i){
        most_time = most_time > times[i] ? most_time : times[i];
        most_ch = times[most_time];
    }

    return res;
}

int main(){
    string str = "abcabc";
    cout << mostAppearSubstring(str);
    return 0;
}