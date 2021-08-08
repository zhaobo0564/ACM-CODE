#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

ll fn[N];
int main() {
    ios::sync_with_stdio(0);
    fn[0] = 1;
    for (int i = 1; i <= 40; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    int t; cin >> t;
    int res = 0;
    for (int j = 1; j <= t; j++) {
        int n, m;
        cin >> n >> m;
        int ans;

        for (int i = 0; i <= 40; i++) {
            if (n <= fn[i]) {
                ans = i + 1;
                break;
            }
        }
        if (fn[ans - 1] != n) {
            ans--;
        }
    //    cout << ans << endl;
        if (ans <= m) {
            res = res ^ j;
         //   cout << res << endl;
        } else {
       
            res = res ^ (j - 1);
          //  cout << res << endl;
        }

    }
    cout << res << endl;
}