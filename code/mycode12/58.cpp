#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, m;

map<string, int> mp;

string g[N];

void work(string s, int id) {
    string ans = "";
    s += ' ';
    int f = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (f == 0) {
                mp[ans] = id;
            } else {
                g[id] += ans;
                g[id] += ' ';
            }
            ans = "";
            f++;
        } else {
            ans += s[i];
        }
    }
}

void gao(string s) {
    string ans = "";
    s += ' ';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
         //   cout << "ans = " << ans << endl;
            if (mp[ans] != 0) {
                cout << g[mp[ans]];
            } else {
                cout << ans << " ";
            }
            ans = "";
        } else {
            ans += s[i];
        }
    }
    cout << endl;
}

void solve() {
    scanf("%d", &n);
   // fflush(stdin);
    getchar();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
      //  cout << s << endl;
        work(s, i);
        
    }
    scanf("%d", &n);
    getchar();
  //  fflush(stdin);
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
    //    cout << "s = " << s << endl;
        gao(s);

    }

}

int main() {
   // ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}