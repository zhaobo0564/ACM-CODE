#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int n, a[N];
string s;

int judge(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        int k; cin >> k;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            a[i + 1] = judge(s[i]);
           // cout << a[i + 1] << " ";
        }
       // cout << endl;
       a[len + 1] == -1;
        int r = 0, ans = 0, cnt = 0;
        for (int i = 1; i <= len; i++) {
           // cout << a[i] << " ";
            while (r <= len && cnt <= k) {
                if (a[++r] == 0) {
                    cnt++;
                }
            }
          //  cout << "L = " << i << " r = " << r << " " << cnt<< endl;
            ans = max(ans, r - i);
            if (a[i] == 0) {
                cnt--;
            }

        }
       // cout << endl;
        cout << ans << endl;
    }
}