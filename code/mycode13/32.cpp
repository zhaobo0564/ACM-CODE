#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, a, b, l;

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
    cin >> a >> b >> m >> n >> l;
    ll x, y;
    if (m ==  n) {
        cout << "Impossible\n";
    } else {
        if ((b - a) % __gcd(m - n, -l) == 0) {
            exgcd(m - n, -l, x, y);
            
            x = x * ((b - a) / __gcd(m - n, -l));
            // cout << x << " " << y << endl;
            // cout << abs(((-l) / __gcd(m - n, -l))) << endl;
            x = (x % abs(((-l) / __gcd(m - n, -l))) + abs(((-l) / abs(__gcd(m - n, -l))))) % abs(((-l) / __gcd(m - n, -l)));
            cout << x << endl;


        } else {
            cout << "Impossible\n";
        }
    }


}