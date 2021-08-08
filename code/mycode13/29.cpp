#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int vis[100];

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    vector<int> v;
    while (v.size() < n + 2) {
        if (a == 0) {
            v.push_back(0);
        }
        if (a < b) {
            int cnt = 0;
            while (a < b) {
                a = a * 10;
                cnt++;
            }
            for (int j = 1; j < cnt; j++) {
                v.push_back(0);
            }
            if (vis[a / b]) break;
            v.push_back(a / b);
            vis[a / b] = 1;

            a = a % b;
        } else {
            a = a % b;
        }

    }

    int x = v[v.size() - 1];
    int y = v[v.size() - 2];
    int z = v[v.size() - 3];
    cout << z << y << x << endl; 
    
    
}