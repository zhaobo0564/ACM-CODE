#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)  { // ·µ»ØÖµÎª gcd(a, b)
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int main() {
    ll a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
}