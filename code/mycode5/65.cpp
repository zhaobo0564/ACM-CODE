#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
#define ll long long

inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll n, w1, w2, k;
const int N = 2007;

struct node{
    ll x, y;
}p[N];

inline bool cmp(node a, node b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int dp[N];

int main() {
    n = read(), k = read(), w1 =  read(), w2 = read();
    for (int i = 1; i <= k; i++) {
        p[i].x = read(), p[i].y = read();
    }
    if (w1 * 2 <= w2) {
        printf("%lld\n", (n + n) * w1);
        return 0;
    } 
    sort(p + 1, p + k + 1, cmp);

    int cnt = 0;

    for (int i = 1; i <= k; i++) {
        for (int j =  i + 1; j <= k; j++) {
            if (p[j].x > p[i].x && p[j].y > p[i].y) {
                dp[j] = max(dp[i] + 1, dp[j]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cnt = max(dp[i], cnt);
    }
    cnt++;
    ll ans = w1 * 1ll*(n + n - 2 * cnt) + (1ll*cnt) * w2;
    printf("%lld\n", ans);
}