#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

long long hp, k, n, a[N], sum;



bool judge(ll x) {
    
    ll cat = sum * x;
    if (cat >= hp) return true;
    cat = hp - cat;
    ll su = 0;
    for (int i = 1; i <= n; i++) {
        su += a[i];
        if (su >= cat) {
            return true;
        }
    }
    return false;
    
}

int main() {
    ios::sync_with_stdio(0);

    cin >> hp >> n;


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = -a[i];
        sum += a[i];
    }

    if (sum <= 0) {
        int f = 0;
        ll su = 0;
        for (int i = 1; i <= n; i++) {
            su += a[i];
            if (su >= hp) {
                cout << i << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }

    long long  l = 0, r = (hp / sum + 1) + 1;

    long long  ans = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (judge(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
  //  cout << ans << endl;
    long long res = ans * n;
    long long cat = sum * ans;
    cat = hp - cat;

    long long su = 0;
    for (int i = 0; i <= n; i++) {
        su += a[i];
        if (su >= cat) {
            res += i;
            break;
        }
    }


    cout << (res == 0? -1: res) << endl;
    

   

    
}