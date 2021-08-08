#include<bits/stdc++.h>
using namespace std;
int n, d;
double pai = acos(-1);

int main(){
    while(~scanf("%d %d", &n, &d)){
        double ans = 0.0;
        for(int i = 1; i <= n; i++){
            int r; scanf("%d", &r);
            double cnt = pai / 180.0;
            cnt = cnt * (double)r;
            cnt = 0.5 * sin(cnt) * d * d;
            ans += cnt;
        }
        printf("%.3lf\n", ans);
    }
}