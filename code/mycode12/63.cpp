#include<bits/stdc++.h>
using namespace std;
const int N = 100;
typedef long long ll;
int a[N], n, isnot[N];
vector<int>G[N];
int vis[N];
int b[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,  31, 37, 41, 43, 47 };
ll ans = LLONG_MAX;
void dfs(int p, ll sum) {
    if (p >= 15) {
        for (int i = 1; i <= n; i++) {
            if (__gcd(sum, 1ll*a[i]) == 1) {
                return;
            }
        } 
        ans = min(ans, sum);
        return;  
        
    }
    dfs(p + 1, sum * b[p]);
    dfs(p + 1, sum);
}



int main() {
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = i + 1;
       // sort(G[a[i]].begin(), G[a[i]].end());
    }
    dfs(0, 1);
   
    cout << ans << endl;
    return 0;
}

//2 3 5 7 11 13 17 19 23 29  31 37 41 43 47 