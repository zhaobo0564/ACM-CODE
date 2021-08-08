#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

vector<int> v;
int vis[11];

ll ans = 0;

void dfs(int p) {
    if (p > 9) {
        ll a = 0, b = 0, c = 0;
        for (int i = 0; i < v.size(); i++) {
            a = a * 10 + v[i];
            b = 0;
            for (int k = i + 1; k < v.size(); k++) {
                b = b * 10 + v[k];
                c = 0;
                for (int z = k + 1; z < v.size(); z++) {
                    c = c * 10 + v[z];
                    
                }
                if (a && b && c && b % c == 0 && (a + (b / c)) == n) {
                      //  cout << a << " " << b << " " << c << endl;
                        ans++;
                }
            }
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            v.push_back(i);
            dfs(p + 1);
            vis[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
}