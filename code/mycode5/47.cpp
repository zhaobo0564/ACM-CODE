#include<bits/stdc++.h>
using namespace  std;

typedef long long ll;

int n;
string s;


vector<pair<int, int> >v;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> s;
    int r = 0;
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            w++;
        } else {
            r++;
        }
    }
    int ans = min(w, r);
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        if (s[i] == 'R') {
            cnt++;
        }
    }
    ans = min(ans, r - cnt);
    cnt = 0;
    for (int i = n - 1; i >= n - w; i--) {
        if (s[i] == 'W') {
            cnt++;
        }
    }
    ans = min(ans, w - cnt);
    cout << ans << endl;



    


    
}