#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string a, n;

int fn[20];

ll dfs(ll x, ll mod) {
    if (mod == 1) return 1;
    return pow(x, dfs(x, fn[mod]) + fn[mod]);
}

int main() {
    fn[10] = 4;
    fn[4] = 2;
    fn[2] = 1;
    fn[1] = 1;
    cin >> a >> n;
    ll base = 0;
    for (int i = 0; i < a.length(); i++) {
        base = base * 10 - (a[i] - '0');
        base = base % 10;
    }
    if (n.length() == 1) {
        int cnt = n[0] - '0';
        
        
    } else {
        cout << pow(base, dfs(base, fn[10]) + fn[10]) % 10;
    }

}