#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;

typedef long long ll;

ll mp[N][N], n, m, sum[N][N], a, b, cnt[N][N],x[N];


void solve() {
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
 
    for (int i = 0; i <= n + a; i++) {
        for (int j = 0; j <= m + b; j++) {
            mp[i][j] = 0;
            cnt[i][j] = 0;
            x[j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &mp[i][j]);
        }
    }
   // print();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll cat = mp[i][j] - cnt[i][j] - x[j];
            if (cat < 0) {
                cout << "QAQ\n";
                return;
            }
            if (i + a - 1 <= n && j + b - 1 <= m) {
                x[j] += cat;
                x[j + b] -= cat;
                cnt[i + a][j] -= cat;
                cnt[i + a][j + b] += cat;
            }
            
            x[j + 1] += x[j];
        }
      //  print();
        for (int j = 1; j <= m; j++) {
            cnt[i + 1][j + 1] += cnt[i + 1][j];
        }
        for (int j = 1; j <= m + 1; j++) {
            cnt[i][j] += x[j];
            x[j] = 0;
        } 
        for (int j = 1; j <= m; j++) {
            cnt[i + 1][j] += cnt[i][j]; 
        }
        
    }



    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            if (mp[i][j] != cnt[i][j]) {
                cout << "QAQ" << endl;
              
                return;
            }
            // cout << cnt[i][j] << " ";
        }
        // cout << endl;
    }
    cout << "^_^\n";

    


  
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}

/*
2 2 1 1 
1 2
1 2

2 3 1 2
1 3 1
1 3 1

2 4 1 2
2 3 3 2
7 7 6 6

1 4 1 2
2 3 3 1

1 4 1 4
4 5 5 5

1 7 1 2
100 100 1 2 1 98 98

*/