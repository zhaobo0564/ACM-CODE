#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

long long a[N], m, n;

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(m >= a[i]){
            m -= a[i];
            ans++;
        }
    }
    printf("%d\n", ans);
}