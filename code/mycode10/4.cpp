#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

int a[N], n;

int cal(int pos) {
    if (a[pos] > a[pos - 1] && a[pos] > a[pos + 1]) {
        return 1;
    } else if (a[pos] < a[pos - 1] && a[pos] < a[pos + 1]) {
        return 1;
    }
    return 0;
}

int work(int pos) {
    int ans = 0;
    if (pos > 2 && pos < n - 1) {
       ans += cal(pos);
       ans += cal(pos - 1);
       ans += cal(pos + 1);
        
    } else if (pos < n - 1) {
        ans += cal(pos);
        ans += cal(pos + 1);
    } else if (pos > 2){
        ans += cal(pos);
        ans += cal(pos - 1);
    } else if (pos == 2 && pos == n - 1) {
        ans += cal(pos);
    }
    return ans;
}

void solve(int j) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << 0 << endl;
    } else {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += cal(i);
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            int temp = a[i];
            int cnt = work(i);
            a[i] = a[i - 1];
            int cnt1 = work(i);
            a[i] = a[i + 1];
            int cnt2 = work(i);
            a[i] = temp;
            res = max(res, cnt - min(cnt1, cnt2));
        }
        cout <<  ans - res << endl;
    }


}

int main() {
    int t; cin >> t;
    for (int j = 1; j <= t; j++) {
        solve(j);
    }
}