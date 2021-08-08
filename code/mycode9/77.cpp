#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

int a[1007], n;
int sum[N];

vector<int> g[N];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
     // a[i] = 0;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = i; j <= n; j++) {
            ans = ans ^ a[j];
            g[ans].push_back(i);
        }
    }
    for (int i = 0; i < N; i++) {
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = i; j <= n; j++) {
            ans = ans ^ a[j];
            int p = upper_bound(g[ans].begin(), g[ans].end(), j) - g[ans].begin();
            cnt += 1l*(g[ans].size() - p);
        }
    }
    printf("%lld\n", cnt);


    

}