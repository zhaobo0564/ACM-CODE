#include<bits/stdc++.h>
using namespace std;

const int N = 4007;

int a[N], n, t;

vector<int >v;
int dp[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        v.clear();
        v.push_back(0);
        for (int i = 1; i <=  2*n; i++) {
            scanf("%d", &a[i]);
        }
        int l = 1;
        for (int i = 2; i <= 2 * n; i++) {
            if (a[i] < a[l]) {

            } else {
                v.push_back(i - l);
                l = i;
            }
        }
        if (2 * n - l + 1 >= 0) v.push_back(2 * n - l + 1);
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 1; i < v.size(); i++) {
            for (int j = n; j; j--) {
                if (j >= v[i]) {
                    dp[j] = max(dp[j], dp[j - v[i]]);
                }
            }
        }
        if (dp[n]) puts("YES");
        else puts("NO");
    }
}