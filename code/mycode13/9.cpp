#include<bits/stdc++.h>

using namespace std;
int n, q;
const int N = 1e5 + 7;
string s[N];
char vi[N];
set<char>v;

string work(string str) {
    char a = '1';
    for (int i = 0; i < str.length(); i++) {
        vi[str[i]] = '0';
    }
    for (int i = 0; i < str.length(); i++) {
         if (vi[str[i]] == '0') {
             vi[str[i]] = a;
             a++;
         }
         str[i] = vi[str[i]];
    }
  

    return str;
    
}

map<string, int> vis;
int top = 1;

vector<int> g[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = work(s[i]);
        //cout << s[i] << endl;
        if (vis[s[i]] == 0) {
            vis[s[i]] = top++;
        }
        g[vis[s[i]]].push_back(i);
    }
    while (q--) {
        string name;
        int l, r;
        cin >> name;
        name = work(name);
        cin >> l >> r;
        int pos = vis[name];
        int p = upper_bound(g[pos].begin(), g[pos].end(), r) - g[pos].begin();
        int pp = lower_bound(g[pos].begin(), g[pos].end(), l) - g[pos].begin();
        cout << p - pp << endl;
    }

}