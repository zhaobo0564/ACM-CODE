#include<bits/stdc++.h>
using namespace std;

const int N = 107;
int dp[N][N];

char s[N], t[N];

// int dfs(int i, int j) {
//     if (j == t.length()) return 1;
//     if (i == s.length()) return 0;
//     if (dp[i][j] != -1) return dp[i][j];
//     int ans = 0;
//     if (s[i] == t[j]) {
//        ans = max(ans, dfs(i + 1, j + 1));
//     }
//     if(s[i] == '(') {
//         int l = 0;
//         for (int z = i; z < s.length(); z++) {
//             if (s[z] == '(') {
//                 l++;
//             } else {
//                 l--;
//             }
//             if (l == 0) {
//                 ans = max(ans, dfs(z + 1, j));
//                 break;
//             }
//         }
//     }
//     dp[i][j] = ans;
//     return ans;
// }

int main() {
    string a[2];
    a[0] = "Impossible";
    a[1] = "Possible";
    cin >> (s + 1) >> (t + 1);
    //memset(dp, -1, sizeof(dp));
    //cout << a[dfs(0, 0)] << endl;
    int ls = strlen(s + 1), lt = strlen(t + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= ls; i++) {
        for (int j = 1; j <= lt; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            } 
            if (s[i] == '(') {
                int l = 0;
                for (int k = i; k <= ls; k++) {
                    if (s[k] == '(') l++;
                    else l--;
                    if (l < 0) break;
                    if (l == 0) {
                        if (k + 1 <= ls && s[k + 1] == t[j]) {
                            dp[k + 1][j] = max(dp[k + 1][j], dp[i - 1][j - 1]);
                        }
                        //break;
                    }
                }
            }
        }
    }
    // for (int i = 1; i <= ls; i++) {
    //     for (int j = 1; j <= lt; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int ans = 0;
    for (int i = 1; i <= ls; i++) {
        if (dp[i][lt]) {
            ans = 1;
            break;
        }
    }

    cout << a[ans] << endl;
}