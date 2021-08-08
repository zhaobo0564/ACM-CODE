#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

ll a[N], n, b[N], c[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    ll maxa = 0, maxb = 0;
    for (int i = 1; i <= n; i++) {
        maxa = max(maxa, a[i]);
        c[i] = max(maxa * b[i], c[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << c[i] << endl;
    }
    


}


