#include <bits/stdc++.h>
using namespace std;
const int N = 107;
double a[N][N];
double eps = 1e-9;
int n;


int gauss() {
    for (int i = 1;i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++) {
            if(fabs(a[r][i]) < fabs(a[j][i])) {
            	r = j;    
            }
        }
        if (r != i) {
            for (int j = 1;j <= n+1; j++) {
                swap(a[i][j],a[r][j]);
            }
        }
        
        if (fabs(a[i][i]) < eps){
            return 0;	// нч╫Б
        }
        for (int j = 1;j <= n; j++) {
            if (j != i){
                double tmp = a[j][i] / a[i][i];
                for(int k = i+1; k <= n+1; k++) {
                    a[j][k] -= a[i][k] * tmp;
                }
                
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        a[i][n+1] /= a[i][i];
    }
    
    return 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cin >> a[i][j];
        }
    }
    if (gauss()) {

        for (int i = 1; i <= n ; i++) {
            printf("%.2lf\n", a[i][n + 1]);
        }
    } else {
        puts("No Solution");
    }
}