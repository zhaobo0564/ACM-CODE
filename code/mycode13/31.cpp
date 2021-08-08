#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

typedef long long ll;
ll A[N], B[N], n;

map<pair<ll, ll>, int >vis;

set<int> v;
int ans = 0;

int main() {
    cin >> n;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
        if (vis[{A[i], B[i]}] == 0) {
            v.insert(A[i]);
            ans++;
        }
        vis[{A[i], B[i]}] = 1;
    }
    
    if (v.size() == 1) {
        cout << ans  + 1 << endl;
    } else {
        cout << ans * 2 << endl;
    }
}