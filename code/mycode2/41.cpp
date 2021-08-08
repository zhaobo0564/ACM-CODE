#include<bits/stdc++.h>
using namespace std;

int n, x;
long long a[200007];

int main(){
    scanf("%d %d", &n, &x);

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        sum += a[i];

    }

    if(x > n){
        printf("%lld\n", sum);
    }else{
        long long ans = 0;
        sort(a + 1, a + n + 1);
        int cnt = 0;
        ans += a[n - x] * x;
        for(int i = n - x + 1; i <= n; i++){
            ans += (a[i] - a[n - x]);
        } 
        printf("%lld\n",ans);
    }
}