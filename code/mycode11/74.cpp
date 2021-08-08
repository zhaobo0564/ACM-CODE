#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1007;

int a[N];

deque<int> q;
int vis[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (q.size() == 0) {
            ans++;
            q.push_back(a[i]);
            vis[a[i]]++;
        } else {
            if (vis[a[i]] == 0) {
                ans++;
                q.push_back(a[i]);
                vis[a[i]]++;
                while (q.size() > n) {
                    int cd = q.front();
                    vis[cd]--;
                    q.pop_front();
                }                
            }
        }
    }
    cout << ans << endl;

}