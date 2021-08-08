#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
int a[N], b[N], n, A[N], B[N];

map<pair<int, int>, int> vis;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        vis[{a[i], b[i]}] = 1;
    }
    int top = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[{a[i], b[i]}]) {
            A[top] = a[i];
            B[top] = b[i];
            top++;
            vis[{a[i], b[i]}] = 0;
        }
    }

    int ans = 2;
    for (int i = 2; i < top; i++) {
        set<pair<double, double> >s;
        for (int j = 1; j < i; j++) {
            if (A[i] == A[j]) continue; //斜率相等平行
            double x = (double)(B[j] - B[i]) / (double) (A[i] - A[j]);
            double y = (double)A[i] * x + (double) B[i];
            s.insert({x, y});
        }
        ans += s.size() + 1;
    }
    cout << ans << endl;
}