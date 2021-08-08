#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000;
ll n, m, mp[N][N];


ll work(int x, int y) {
    ll cnt = 0;
    int maxn  = 0;
    for (int i = x ; i; i--) {
        for (int j = y; j; j--) {
            if (j <= maxn) break;
            if (mp[i][j]) {
                maxn = max(maxn, j);
                break;
            }
            cnt++;
        }
    }
    ll one = 0;   
    for (int j = y; j; j--) {
        if (mp[x][j]) break;
        one++;
    } 
    ll two = 0;
    for (int j = x; j; j--) {
        if (mp[j][y]) break;
        two++;
    }
    ll ul = cnt - one - two + 1;
    cnt = 0;
    int minn = 1e8;
    for (int i = x; i; i--) {
        for (int j = y; j <= m; j++) {
            if (j >= minn) break;
            if (mp[i][j]) {
                minn = min(minn, j);
                break;
            }
            cnt++;
        }
    }
    ll three = 0;
    for (int j = y; j <= m; j++) {
        if (mp[x][j]) break;
        three++;
    }
    ll ur = cnt - three - one + 1;
    cnt = 0;
    maxn = 0;
    for (int i = x; i <= n; i++) {
        for (int j = y; j; j--) {
            if (j <= maxn) break;
            if (mp[i][j]) {
                maxn = max(maxn, j);
                break;
            }
            cnt++;
        }
    }

    ll four = 0;
    for (int j = x; j <= n; j++) {
        if (mp[j][y]) break;
        four++;
    }
    ll dl = cnt - two - four + 1;
    cnt = 0;
    minn = 1e8;
    for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
            if (minn <= j) break;
            if (mp[i][j]) {
                minn = min(minn, j);
                break;
            }
            cnt++;
        }
    }
    
    ll dr = cnt - three - four + 1;
    printf("ul = %lld, ur = %lld, dl = %lld, dr = %lld\n", ul, ur, dl, dr);
    printf("one = %lld, two = %lld, three = %lld, four == %lld\n", one, two, three, four);
    ll ans = ur + ul + dl + dr;
    ans += dl * ur + ul * dr;
    ans += dl * dr + ul * ur;
    ans += dl * ul + dr * ur;
    cout << "ans  " << ans << endl;
    ans += one + three + two + four - 3;
    ans += (one - 1)* (four - 1) + (two - 1) * (three - 1);
    mp[x][y] = 1;
    return ans;
}

int main() {
    scanf("%lld %lld", &n, &m);
    ll ans = (n * (n + 1) / 2) * (m * (m + 1) / 2);
    cout << "ans " << ans << endl;
    for (int i = 1; i <= n * m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        ll cnt = work(x, y);
        cout << "cnt " << cnt << endl;
        ans -= cnt;
        printf("%lld\n", ans);
    }
}