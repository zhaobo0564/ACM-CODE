#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll a[N], n;

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum = sum ^ a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << (sum ^ a[i]) << " ";
    }
    cout << endl;

}