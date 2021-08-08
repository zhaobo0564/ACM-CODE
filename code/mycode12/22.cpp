#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+ 7;
int a[N], n;
typedef long long ll;

vector<int> g;

int sum[N], vis[N];


int main() {
    for (int i = 0; i <= 1000000; i++) {
        int cnt = sqrt(i);
        if (cnt * cnt == i) {
            g.push_back(i);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    vis[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j: g) {
            if (sum[i] >= j) {
                int cnt = sum[i] - j;
                ans += vis[cnt];
            } else {
                break;
            }
        }
        vis[sum[i]]++;
    }
    cout << ans << endl;
    
}