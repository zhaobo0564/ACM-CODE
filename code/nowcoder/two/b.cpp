#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
int mp[5007][5007];

int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}

int maxn[5007][5007];
deque<int>q;
int main () {
    scanf("%d %d %d", &n, &m, &k);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mp[i][j] = lcm(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        q.clear();
        for (int j = 1; j <= m; j++) {
            while (!q.empty() && mp[i][q.front()] < mp[i][j]) {
                q.pop_back();
            }
            q.push_back(j);
            while(!q.empty() && q.front() <= j - k) {
                q.pop_front();
            }
            maxn[i][j] = mp[i][q.front()];
        }
    }


    for (int i = 1; i <= m; i++) {
        q.clear();
        for (int j = 1; j <= n; j++) {
            while (!q.empty() && maxn[q.front()][i] < maxn[j][i]) {
                q.pop_back();
            }
            q.push_back(j);
            while(!q.empty() && q.front() <= j - k) {
                q.pop_front();
            }
            mp[j][i] = maxn[q.front()][i];
        }
    }

    ll ans = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans += mp[i][j];
        }
    }
    printf("%lld\n", ans);


    


}