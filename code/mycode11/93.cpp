#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int n, m, w[N];

vector<int> g[N];


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            g[i].push_back(x);
        }
        cin >> w[i];
    }
    
}