#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[300];

bool judge(int x, int y, int z) {
    if (x == y || x == z || y == z) 
        return false;
    if (x + y > z && (abs(x  - y) < z)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (judge(a[i], a[j], a[k])) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}