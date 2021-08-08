#include<bits/stdc++.h>
using namespace std;
const int N =60;
typedef long long ll;
ll n;

typedef long long LL;

LL c[100][100];
void C()
{
    int i,j;
    for(i=0;i<N;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<N;i++)
        for(j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
}

void solve() {
   cin >> n;
    ll ans = c[n][n / 2];
   ans = ans / 2;
   ll cnt = 1;
   for (ll i = 1; i < n / 2; i++) {
       cnt = cnt * i;
   }
   ans = ans * cnt * cnt;
   cout << ans << endl;
   
}

int main() {
    C();
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}