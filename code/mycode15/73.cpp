#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long ll;
double r, a, b, h;
double eps = 0.0000000000000001;

int main() {
    cin >> r >> a >> b >> h;
    double R = r + r;
    double cnt = R / a;
    double cnt1 = b / R;
    cout << cnt << endl;
    if (fabs(cnt - cnt1) <= eps) {
        double ans = h * cnt;
        puts("Stuck");
        printf("%lf\n", ans);
    } else {
        puts("Drop");
    }
}