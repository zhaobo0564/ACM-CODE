#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;
char s[N];

int dp[10];

int sum[N][300];

vector<int> g[300];
char t[] = "NowCoder";
// bool judge(int l, int r) {
//     // NowCoder
    
//     vector<int> v;
//     v.push_back(l - 1);
//     for (int i = 0; i < 8; i++) {
//         int pos = lower_bound(g[t[i]].begin(), g[t[i]].end(), l) - g[t[i]].begin();
//         if (pos < g[t[i]].size()) {
//             l = g[t[i]][pos];
//             v.push_back(l);
//         } else {
//             return false;
//         }
//     }
//     if (l > r) return false;
//     if (sum[v[1]]['N'] - sum[v[0]]['N'] != 1) {
//         return false;
//     } 

//     int p = 2;
//     for (int i = 1; i < 8; i++) {
//       //  cout << "l = "<< v[p] << " " << v[p - 1] << endl;
//         if (sum[v[p]][t[i - 1]] - sum[v[p - 1]][t[i - 1]] != 0) {
//             return false;
//         }
//         if (sum[v[p]][t[i]] - sum[v[p - 1]][t[i]] != 1) {
//             return false;
//         }
//         p++;

//     }
//     return true;
    
    
// }
int vis[400];

bool judge(int pos) {
    for (int i = 0; i < 8; i++) {
        if (s[i + pos] == t[i]) {

        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cout <<"ÖÐËÙÐÐÊ»" << endl;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    // for (int i = 1; i <= n; i++) {
    //     g[s[i]].push_back(i);
    //     vis[s[i]]++;
    //     for (int j = 0; j < 8; j++) {
    //        sum[i][t[j]] = vis[t[j]]; 
    //     }
        
        
    // }
    ll ans = 0;
    ll last = 0;
   // judge(1, 8);
    for (ll i = 1; i <= n; i++) {
        if (i + 7 <= n) {
            if (judge(i)) {
                //cout << i << endl;
                ans += (i - last) * (n - (i + 7) + 1);
                last = i;
            }
        }

    }
    cout << ans << endl;
}