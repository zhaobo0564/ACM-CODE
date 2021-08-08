#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
vector<int> v;

void add() {
    int l = v.size();
    l--;
    while (v[l] == 0) l--;
    v[l] = 0;
    l--;
    while(l) {
        if (v[l] < 9) {
            v[l]++;
            break;
        } else {
            v[l] = 0;
            l--;
        }
    }
    if(l == 0) v[0]++;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll  s;
        v.clear();
        string n;
        cin >> n >> s;
        int l = n.length();
        v.push_back(0);
        ll ans = 0;
        ll base = 0;
        for (int i = 0; i < l; i++) {
            v.push_back(n[i] - '0');
            ans += n[i] - '0';
            base = base * 10 + n[i] - '0';
        }
        if (ans <= s) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= l; i++) {
            add();
            // for (int j : v) {
            //     cout << j;
            // }
            // cout << endl;
            ans = 0;
            for (int j: v) {
                ans += j;
            }
          //  cout << ans << endl;
            if (ans <= s) {
                ll cnt = 0;
                for (int j = 0; j < v.size(); j++) {
                    //cout << v[j];
                    cnt = cnt * 10 + v[j];
                }
               // cout << endl;
                cout << cnt - base << endl;
                break;

            }
        }

    }
}