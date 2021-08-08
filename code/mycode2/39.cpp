#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n - m; i++){
        int x; scanf("%d", &x);
        sum += x;
    }

    double ans = (double)(sum + m * 5 ) / (double)n;
    double ans1 = (double)(sum + m) / (double)n;
    printf("%.5lf %.5lf\n", ans1, ans);
}