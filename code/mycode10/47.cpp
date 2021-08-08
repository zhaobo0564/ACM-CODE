#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(l, r) for (int i = l; i <= r; i++)
const int N = 2e5 + 7;

int a[N], n, k, b[N];


void solve() {
    cin >> n >> k;

    int l = 1;
    int end = 2 * k - n;
    int pos = 1;
    int f = 1;
    while (1) {
        a[pos++] = l;
        l += f;
        if (l > k) {
            f = -1;
            l--;
        }
        if (f == -1 && l < end) {
            break;
        }
    }
    pos--;
    int cnt = pos - k;
    for (int i = 1; i <= pos; i++) {
        b[i] = a[i];
    }
    
    for (int i = 1; i <= cnt; i++) {

    }

}


int main() {
    int t; cin >> t;
    while (t--) {
       solve();
    }

}