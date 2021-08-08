#include<bits/stdc++.h>
using namespace std;

int n;
map<string, int> vis;

int main() {
    while (~scanf("%d", &n)) {
        int ans = 0;
        vis.clear();
        for (int i = 1; i <= n; i++) {
            string name;
            cin >> name;
            

            if (vis[name] == 0) {
                vis[name] = 1;
                ans++;
            }
        }
        cout << ans << endl;
        
    }
}