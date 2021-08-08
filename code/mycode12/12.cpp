#include<bits/stdc++.h>
using namespace std;
const int N = 300;

int mp[N][N], u, r, d, l, n;

int ok = 0;

void dfs(int f, int uu, int dd, int rr, int ll) {
    if (f > 4) {
        
        ok = 1;
        return;
    }
    if (f == 1) {
        if (uu == n) {
            dfs(2, 0, dd, rr - 1, ll - 1);
        } else if (uu == n - 1 ) {
            dfs(2, 0, dd, rr - 1, ll);
            dfs(2, 0, dd, rr, ll - 1);
            if (uu > 1)
                dfs(2, 0, dd, rr - 1, ll - 1);
        } else if (uu > 1) {
            dfs(2, 0, dd, rr - 1, ll);
            dfs(2, 0, dd, rr, ll - 1);
            dfs(2, 0, dd, rr - 1, ll - 1);
            dfs(2, 0, dd, rr, ll);
        } else if (uu == 1) {
            dfs(2, 0, dd, rr - 1, ll);
            dfs(2, 0, dd, rr, ll - 1);
            dfs(2, 0, dd, rr, ll);
        } else if (uu == 0){
            dfs(2, 0, dd, rr, ll);
        } else {
            return;
        }
    } else if (f == 2) {
        if (dd == n) {
            dfs(3, 0, 0, rr - 1, ll - 1);
        } else if (dd == n - 1) {
            dfs(3, 0, 0, rr - 1, ll);
            dfs(3, 0, 0, rr, ll - 1);
            if (dd > 1)
                dfs(3, 0, 0, rr - 1, ll - 1);
        } else if (dd > 1) {
            dfs(3, 0, 0, rr - 1, ll - 1);
            dfs(3, 0, 0, rr - 1, ll);
            dfs(3, 0, 0, rr, ll - 1);
            dfs(3, 0, 0, rr, ll);
        } 
        else if (dd == 1) {
            dfs(3, 0, 0, rr - 1, ll);
            dfs(3, 0, 0, rr, ll - 1);
            dfs(3, 0, 0, rr, ll);
        } else if (dd == 0){
            dfs(3, 0, 0, rr, ll);
        } else {
            return;
        }
    } else if (f == 3) {
        if (rr == n) {
        
            
        } else if (rr == n - 1) {
            
           
        } else if (rr > 1) {
           
            dfs(4, 0, 0, 0, ll);
           
        }
         else if (rr == 1) {
          
            dfs(4, 0, 0, 0, ll);
        } else if (rr == 0){
            dfs(4, 0, 0, 0, ll);
        } else {
            return;
        }
    } else if (f == 4) {
       if (ll == n) {
           
            
        } else if (ll == n - 1) {
        
        } else if (ll > 1) {
          
            dfs(5, 0, 0, 0, 0);
        } 
        
        else if (ll == 1) {
            dfs(5, 0, 0, 0, 0);
        } else if (ll == 0){
            dfs(5, 0, 0, 0, 0);
        } else {
            return;
        }
    }
}


void solve() {
    cin >> n >> u >> r >> d >> l;
    ok = 0;
    dfs(1, u, d, r, l);
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
        
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
