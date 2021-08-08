#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

ll dp[4];
const ll mod = 1e9 + 7;



int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C') {
            if (dp[0]) {
                dp[1] += dp[0];
            } 
            dp[0] += 1;
        } else if (s[i] == 'S') {
            if (dp[1]) {
                dp[2] += dp[1];
            }
        } else if (s[i] == 'U') {
            if (dp[2]) {
                dp[3] += dp[2];
            }
        }
        dp[0] = dp[0] % mod;
        dp[1] = dp[1] % mod;
        dp[2] = dp[2] % mod;
        dp[3] = dp[3] % mod;
    }
    cout << dp[3] << endl;
}