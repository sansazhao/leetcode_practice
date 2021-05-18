#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main(){
    int m, n;
    int ans = -1;
    cin >> n >> m;
    if(m < 1 || n < 1){
        cout<<0<<endl;return 0;
    }
    if(m == 1 || n == 1){
        cout<<1<<endl;return 0;
    }
    set<long>color_set;
    queue<long>q;
    long color;
    for(int i = 0; i < n; i++){
        scanf("%ld", &color);
        color_set.insert(color);
        q.push(color);
        if(color_set.size() == m){
            if(ans <= 0 || (ans > 0 && ans > q.size())){
                ans = q.size();
            }
        }
        if(color == q.front() && q.size() > 1){
            q.pop();
        }
    }
    cout << ans << endl;
    q.empty();
    color_set.empty();
    return 0;
}