#include<bits/stdc++.h>
using namespace std;
const int N = 20;
double c[N][N], a[N][N], b[N];
int n;
double eps = 0.0000000001;


int gauss() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (fabs(a[j][i]) > eps) {
                for (int k = 1; k <= n; k++) {
                    swap(a[i][k], a[j][k]);
                }
                swap(b[i], b[j]);
        
            }
        }
        if (fabs(a[i][i]) < eps) {
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            double rate = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= rate * a[i][k];
            }
            b[j] -= b[i] * rate;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%.3lf\n", b[i] / a[i][i]);
    }
    return 1;
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &c[i][j]);
        }
    }

    for (int i = 2; i <= n + 1; i++) {
        double ans = 0.0;
        for (int j = 1; j <= n; j++) {
            a[i - 1][j] = -(2 * c[1][j] - 2 * c[i][j]);
            ans += (c[1][j] * c[1][j] - c[i][j] * c[i][j]);
        }
        b[i - 1]= -ans;
    }
    gauss();
}