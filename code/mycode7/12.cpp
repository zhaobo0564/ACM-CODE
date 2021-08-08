#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;

int n, k;

char s[N];

struct node{
    int pos, len;
};

vector<node> g;

bool cmp(node x, node y) {
   
    return x.len < y.len;
}

void solve() {
    g.clear();
    cin >> n >> k;
    cin >> (s + 1);
    int w = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') w++;
    }
    if (w + k >= n) {
        cout << (n - 1) * 2 + 1 << endl;
    } else {
        int sum = 0;
       
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i + 1]) {
                if (s[i] == 'W') {
                    int pos = i + 1;
                    for (int j = i + 1; j <= n; j++) {
                        if (s[j] == 'L') {
                            sum++;
                            pos = j;
                        } else {
                            break;
                        }
                    }
                    if (pos == n) break;
                  
                    g.push_back({i, sum});
                    i = pos;
                    sum = 0;
                }

            } 
        }
        sort(g.begin(), g.end(), cmp);
        
        for (auto it: g) {
            for (int i = it.pos + 1; i <= it.pos + it.len; i++) {
                if (k <= 0) break; 
                k--;
                s[i] = 'W';
               
                
            }
            if (k <= 0) break;
        }

        int ans = 0;
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'W' && f == 0) {
                ans++;
                f = 1;
            } else if (f == 1 && s[i] == 'W') {
                ans += 2;
            } else if (s[i] == 'L') {
                f = 0;
            }
        }
        if (k) {
            if (ans) 
                ans += 2 * k;
            else 
                ans = 2 * k - 1;
           
        }
        cout << ans  << endl;
    }
}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}