#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define MAX 1000
using namespace std;

int res[1000];
void multiply(string a, string b){
    int la = a.size(), lb = b.size();
    memset(res, 0, 1000);
    for (int i = 0; i < la; ++i) {
        for (int j = 0; j < lb; ++j) {
            res[i+j] += (a[i]-'0') * (b[j]-'0');
        }
    }
    for (int i = la+lb-1; i > 0; --i){
        res[i-1] += res[i]/10;
        res[i] %= 10;
    }
    int pos = 0;
    for (int i = 0; i < la+lb-1; ++i){ 
        if (res[i])
            pos = 1;
        if (pos || i == la+lb-2)
            printf("%d", res[i]);
    }
    return;
}

int main(){
    string a = "4", b = "2222"; 
    int x = a.size(), y = b.size();
    multiply(a, b);
    return 0;
}