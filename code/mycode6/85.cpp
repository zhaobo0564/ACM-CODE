#include<bits/stdc++.h>
using namespace std;
const int N = 2000;

int vis[N];





int main() {
    int n, m;
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        int pos = 1, ans;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            while(1) {
                if (vis[pos] == 0) {
                    cnt++;
                    
                }
                if (cnt == m) {
                    ans = pos;
                    vis[pos] = 1;
                    break;
                }
                pos++;
                if (pos > n) pos = 1; 
            }
            
            
        }
        cout << ans << endl;
        
    }
}