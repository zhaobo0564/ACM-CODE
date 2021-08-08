#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int vis[1000];

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
            if (vis[a % b]) break;
            v.push_back(a / b);
           
            a = a % b;
            vis[a] = 1;
        } else {
            a = a % b;
        }

    }

    n = n % v.size();
    if (n == 0) n = v.size();
    int cnt = v.size();
    for (int i = 0; i < cnt; i++) {
        v.push_back(v[i]);
    }
    for (int i = 0; i < v.size() ; i++) {
        if (i + 1 == n) {
            cout << v[i] << v[i + 1] << v[i + 2] << endl;
        }
    }

    return 0;
    
}