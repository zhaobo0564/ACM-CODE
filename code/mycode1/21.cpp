#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

typedef long long ll;

ll dp[N], last[N], a[N];
const int inf=0x7ffffff;

int main(){
    int n, m;
    while(~scanf("%d %d", &m, &n)){
        for(int i = 1;  i <= n; i++){
            scanf("%lld", &a[i]);
            dp[i] = last[i] = 0;
        }

        // for(int i = 1; i <= m; i++){
        //     for(int j = 1; j <= n; j++){
        //         dp[i][j] = dp[i - 1][j];

        //         for(int k = j - 1; k<= i - 1; k++){
        //             dp[i][j] = max(dp[k][j - 1], dp[i][j]);
        //         }
        //     }
        // }

        // memset(dp, 0, sizeof(dp));
        // memset(last, 0, sizeof(last));

        ll mx;
        for(int i = 1; i <= m; i++){
            mx = -inf;
            for(int j = i; j <= n; j++){
             //   cout << last[j - 1] << endl;
             //   cout << a[j] << endl;

                dp[j] = max(dp[j - 1], last[j - 1]) + a[j];
            //    last[j - 1] = mx;
            //    mx = max(dp[j], mx);

              //  cout <<dp[j - 1] << " "<< dp[j] << endl;
            }

            for(int j = i; j <= n; j++){
                mx = max(dp[j], mx);
                last[j] = mx;
            }

        }
        for(int i = m; i <= n; i++){
            dp[m] =max(dp[m], dp[i]);
        }
        cout <<dp[m] << endl;
    }

}