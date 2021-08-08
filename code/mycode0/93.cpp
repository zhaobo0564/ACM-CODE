#include<bits/stdc++.h>
using namespace std;

int n;
double v, u;
const int N = 1007;
double c[N], d[N];

int main(){
    scanf("%d %lf %lf", &n, &v, &u);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &c[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%lf", &d[i]);
    }

    double sum = n * u;
    double cnt = (n) * (n - 1) / 2;
    cnt  = cnt / (double)n;
    double t = 0.0;
    for(int i = 1; i <= n; i++){
    
       for(int j = 0; j < n; j++){
           t += sum/(c[i] - d[i]*j - v);
       }

    }

    printf("%.3lf\n", t/n);



}