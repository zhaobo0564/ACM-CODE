#include <bits/stdc++.h>
using namespace std;

string s, t;

map<string, int> vis;
int v[200];

inline bool judge(string a) {
    int cnt[200];
    for(int i = 'a'; i <= 'z'; i++)cnt[i] = 0;
    for(int i = 0; i < a.length(); i++) {
        cnt[a[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if(cnt[i] != v[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> t >> s;
    int lt = t.length();
    int ls = s.length();
    for (int i = 0; i < lt; i++) {
        v[t[i]]++;
    }
    string a = "";
    int ans = 0;
    for(int i = 0; i < ls; i++) {
        if(i + lt > ls) break;
        a = "";
        int f = 0;
        for(int j = i + lt - 1; j >= i; j--) {
            if(v[s[j]] == 0){
                f = 1;
                break;
            }
            a += s[j];
        }
        if(f == 1)continue;
        if (vis[a] == 0) {
            vis[a] = 1;
            if(judge(a)) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}