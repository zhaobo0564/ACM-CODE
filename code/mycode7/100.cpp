#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;

int main() {
    while (~scanf("%lld %lld %lld %lld", &a, &b, &c, &d)) {
        ll cnt = (a + b) * (b - a  + 1);
        cnt = cnt / 2;
        cout << cnt << endl;
        cnt = cnt % c;
    
        printf("%lld\n", cnt);
    }
}