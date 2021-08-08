#include<bits/stdc++.h>
using namespace std;

int main() {
    long  double a, b;
    int k;
    cin >> a >> b >> k;
    if (k == 1) {
        printf("%.10Lf\n", a);
    } else if (k == 2) {
        printf("%.10Lf\n", b);
    } else {
        long double ans = 0.0;
        for (int i = 3; i <= k; i++) {
            ans = (1.0 +  b) / a;
            a = b;
            b = ans;
        }
        printf("%.10Lf\n", ans);
        //cout << ans << endl;
    }
    
}