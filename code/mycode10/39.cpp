#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;


int a[N], n, m;

bool judge(double x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt =(int)( (double)a[i] / x);
        ans += cnt;
    }
    if (ans >= m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = 1, r = 1e9, ans;
    
    while (fabs(r - l) > 0.0000001) {
        double mid = (l + r) / 2.0;
        //cout << mid << endl;
        if (judge(mid)) {
            ans = mid;
            l = mid + 0.0000001;
        } else {
            r = mid - 0.0000001;
        }
    }
    
    printf("%.2f\n", ans);
}