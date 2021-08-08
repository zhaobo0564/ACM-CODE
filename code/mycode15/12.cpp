#include<bits/stdc++.h>
using namespace std;

const int N = 107;

int l[N], r[N], n;

bitset<1000007> dp, temp, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            temp |= (dp << (j * j));
        }
        dp = temp;
        temp = ans;
    }
    cout << dp.count()<< endl;
    return 0;
}