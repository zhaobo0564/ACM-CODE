#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
string s[N];

int cnt[200][200];

int main() {
    
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i].length() == 1) {
            cnt[s[i][0]][0]++;
        } else {
            cnt[s[i][0]][s[i][1]]++;
        }
    }
    scanf("%d", &q);
    while (q--) {
        string name;
        cin >> name;
        int ans = 0;
        if (name.length() == 1) {
            ans += cnt[name[0]][0];
        } else {
            ans += cnt[name[0]][name[1]];
            ans += cnt[name[1]][name[0]];
            if (name[0] == name[1]) {
                ans -= cnt[name[1]][name[0]];
            }
        }
        cout << ans << endl;
    }
}