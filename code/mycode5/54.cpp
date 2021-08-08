#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

int cnt[300];

int main() {

    cin >> s;
    ll ans = 0;
    int f = 0;
    ll cat = 0;
    ll res = 0;
    ll last;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            f = 0;
            ans += cat;
            cat = 0;
            res = 0;
            last = 0;
        } else if (s[i] == 'H') {
            cat += 1;
            last = 1;
        } else if (s[i] == 'C') {
            cat += 13;
            last = 13;
        } else if (s[i] == 'O') {
            cat += 17;
            last = 17;
        } else if (s[i] == ')') {
            int p = i + 1;
            res = 0;
            while (s[p] >= '0' && s[p] <= '9') {
                res = res * 10 + s[p] - '0';
                p++;
            }
           // cout << "res " << res << "cat " << cat << endl;
            i = p - 1;
            if (res)
                cat = cat * res;
        } else {
            int p = i;
            res = 0;
            while (s[p] >= '0' && s[p] <= '9') {
                res = res * 10 + s[p] - '0';
                p++;
            }
           // cout << "res " << res << "cat " << last << endl;
            if (res) {
                cat += last * res;
                cat -= last;
            }
          //  cout << "cat " << cat << endl;
         
            i = p - 1;
        }
    }
    ans += cat;
    printf("%lld\n", ans);
    
    
}