#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const ll mod = 199999;

__int128 fn[N];


inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
char s[N];
//sum 125417041750000
int main() {
    fn[0] = 1;
   // ll inv = ksm(24, mod - 2);
    for (ll i = 1; i <= mod; i++) {
        __int128 cnt = (i + 1) * (i + 1);
       // cnt %= mod;
       __int128 cat = (i + 2) * (i + 3); 
       __int128 ac =  (3 * i + 4);
       cat = cat * ac;
      //  cat = cat % mod;
        cnt = cnt * cat;
      //  cnt %= mod;
        cnt = cnt / 24;
        cnt %= mod;
        fn[i] = cnt * fn[i - 1];
        fn[i] %= mod;

    }
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ans * 10 + (s[i] - '0');
            ans = ans % mod;
        }
        ans = (ans - 1 + mod) % mod;
        cout << "ans " << ans << endl;
        write(fn[ans]);
    }
}