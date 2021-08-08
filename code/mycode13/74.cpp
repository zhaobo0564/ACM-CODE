#include<bits/stdc++.h>
using namespace std;

int work(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x = x / 10;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int ans = 0, sum = 0;
    for (int  i = 1; i <= n; i++) {
        if (i % 10 == 9) {
            sum += work(i);
        }
    }
    cout << sum << endl;
    for (int i = 2; i <= n; i++) {
        ans += abs(work(i) - work(i - 1));
        ans = ans % (1000000007);
    }
    cout << ans << endl;
}