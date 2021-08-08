#include<bits/stdc++.h>
using namespace std;

double a, b, d;
int t;

double G = 6.67430 * 1e-11;

double work() {
    return (G * a * b) / d * d;  
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%lf %lf %lf", &a, &b, &d, &t);
        d = d * 1000;

        double ans = 0.001;
        double va = 0.0;
        double vb = 0.0;
        while (1) {
            double f = work();
            double aa = f / b;
            double ax = va * ans + (aa * ans * ans) / 2;
            double ab = f / a;
            double bx = vb * ans + (ab * ans * ans) / 2;
            va = va + aa * ans;
            vb = vb + ab * ans;
            d = d - ax - bx;
            ans += 0.001;
            if (fabs(ans - t) <= 0.0000000000001) {
                break;
            } 
            
        }
        d = d / 1000.0;
        printf("%.10lf\n", d);
    }
}