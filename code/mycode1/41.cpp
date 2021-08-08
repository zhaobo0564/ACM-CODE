#include<bits/stdc++.h>
using namespace std;
const int N = 2008;
typedef long long ll;
int n, m, k, q;

ll mp[N][N], sum[N][N];

int main(){
    scanf("%d %d %d %d", &n, &m,&k, &q);
    for(int i = 1; i <= k; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        mp[a][b] += 1;
        mp[a][d + 1] += -1;
        mp[c + 1][b] += -1;
        mp[c + 1][d + 1] += 1;
        
     
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            mp[j][i] += mp[j - 1][i];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mp[i][j] += mp[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = mp[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
           cout << mp[i][j] << " ";
        }
        cout << endl;
    }

    while(q--){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ll ans = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
        printf("%lld\n", ans);

    }
    

}
