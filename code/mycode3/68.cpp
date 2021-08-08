#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
char s[N];

typedef long long ll;
ll dp[N][20];
int up[20];
ll cat[N];
ll mod;
int n;


int main(){
    mod = 1000000007;
    int t; scanf("%d", &t);
    while(t--){
        scanf("%s", s );

        n = strlen(s);
        for(int i = 0; i < n; i++){
            cat[i + 1] = s[i] - '0';
        }
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            up[]
        }

        n = work(sum);
        cout << sum << endl;
        ll ans = dfs(n, 1, 0);
        printf("%lld\n", ans % mod);
    }
}