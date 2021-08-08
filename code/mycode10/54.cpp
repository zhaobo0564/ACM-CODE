#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, t, fn[70];

int dfs(ll p, int f) {
    if (p == 1) {
        return f;
    }
    int pos;
    for (int i = 0; i <= 60; i++) {
        if (fn[i] >= p) {
            pos = i;
            break;
        }
    }
    return dfs(p - fn[pos - 1], f ^ 1);
}

int main() {
    cin >> t;
    fn[0] =1;
    for (int i = 1; i <= 61; i++) {
        fn[i] = fn[i - 1] * 2;
    }
  
    while (t--) {
        cin >> n;
        n++;
        cout << dfs(n, 0) << endl;
    }
}