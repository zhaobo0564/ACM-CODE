#include<bits/stdc++.h>
using namespace std;
int t, n, m;
const int N = 1e4 + 7;
long long a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        sort(a + 1, a + n + 1);
        printf("MAX:%lld\n", a[n]);
        printf("MIN:%lld\n", a[1]);
        double ave = (double)sum / double(n);
        printf("AVG:%.2lf\n", ave);

    }

}