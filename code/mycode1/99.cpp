#include<bits/stdc++.h>
using namespace std;
int n;
long long h, l, H, L;


int main(){
    cin >> h >> l >> H >> L;
    double cnt = (double)h / (double)l;
    double cnt1 = (double)H / (double)L;
    if(cnt - cnt1 > 1e-6){
        double x  = (double)(H * l) / (double)(L);
        double res = double(x * l) / 2.0;
        double ans = (double)(l * h) - res;
        printf("%.8lf\n", ans);
    }else {
        double x = (double)(L*h) / (double)(H);
        double res = x *(double)(h) / 2.0;
        printf("%.8lf\n", res);
    }
    
}