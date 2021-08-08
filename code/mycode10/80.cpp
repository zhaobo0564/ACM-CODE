#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N], n, m, k, vis[N];

double dp[N][2];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }

    double sum = 0, cnt = 0;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (vis[i]) {
            dp[i][0] = 1.0;
        } else {
            dp[i][1] = sum / (double) m + 1;
            dp[i][0] = cnt / (double) m;
            
        }
        sum = sum + dp[i][1];
        cnt = cnt + dp[i][0];
        count++;
      //  printf("sum = %.4f , ans = %4.lf\n", sum, dp[i + 1][1] +);
        
            sum -= dp[i + m ][1];
           // printf("dp[%d][1] = %.4f\n", i + m + 1, dp[i + m + 1][1]);
            cnt -= dp[i + m ][0];
  
       
    }
    cout << dp[0][1] << endl;

   

}