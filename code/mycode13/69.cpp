#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

int a[N], b[N], n;

bool judge() {
    for (int i = 1; i < n; i++) {
        if (a[i + 1] < a[i]) {
            return false;
        }
    }
    return true;
}

int work(int f) {
    
    if (judge()) return 0;
    for (int i = 1; i <= 100000; i++) {

        if (f == 1) {
            for (int j = 1; j <= n; j += 2) {
                swap(a[j], a[j + 1]);
            }
            if (judge()) {
                return i;
            }
            f = f ^ 1;
        } else {
            for (int j = 1; j <= n / 2; j++) {
                swap(a[j], a[n / 2 + j]);
            }
            if (judge()) {
                return i;
            }
            f = f ^ 1;
        }
    }
    return 1e7;
}

int main() {
    scanf("%d", &n);
    n += n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int ans = 1e7;
    ans = min(ans, work(0));
 
    for (int i = 1; i <= n; i++) {
        a[i] = b[i];
    }
    ans = min(ans, work(1));
    if (ans > 1000000) ans = -1;
    printf("%d\n", ans);
}