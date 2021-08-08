#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 7;

ll sum[N];

void init(){
    int top = 0;
    for(int i = 1; i <= 4000; i++){
        for(int j = i ; j < N; j += i){
            if(i * i <= j){
                sum[j] += i;
                if(j / i != i){
                    sum[j] += (j / i);
                }
            }
        }
    }
}

int vis[N + 10];

void solve() {
    int c; cin >> c;

    cout << vis[c] << endl;
  
}

int main() {
    init();
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i < N; i++) {
        if (sum[i] > N) continue;
        if (vis[sum[i]] == -1) {
            vis[sum[i]] = i;
        }
    }
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}