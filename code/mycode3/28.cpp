#include <cstdio>
#include <cstring>
  
using namespace std;
  
typedef long long ll;
  
ll dp[20][8];
int digit[25];
  
ll dfs(int deep, ll state, bool lmt) {
    if (!deep) return state ? 1 : 0;
    if (!lmt && dp[deep][state]>=0) return dp[deep][state];
    int i, up = lmt ? digit[deep] : 9;
    ll cnt = 0;
    for (i=0; i<=up; ++i) {
        if (i==7) continue;
        cnt += dfs(deep-1, (state*10+i)%7, lmt && i==up);
    }
    return lmt ? cnt : dp[deep][state]=cnt;
}
  
ll cal(ll num) {
    int k = 1;
    while (num) {
        digit[k++] = num % 10;
        num /= 10;
    }
    return dfs(k-1, 0, true);
}
  
int main()
{
    ll n, m, left, right, mid, tmp;
      
//    printf("%d %d\n", 14-cal(14*1ll), cal(14));
    while (~scanf("%lld%lld", &m, &n)) {
        memset(dp, -1, sizeof(dp));
        left = 0; right = 1LL*1e18;
        tmp = m - cal(m); //
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid-cal(mid) >= tmp+n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        printf("%lld\n", left);
    }
      
    return 0;
}