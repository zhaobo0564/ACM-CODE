#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
int mp[200][200];
int prime[N],vis[N],top=1;

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}

void solve() {

    int n; cin >> n;

    if (n <= 70) {
        int cnt = 31469 - n + 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    cout << cnt << ' ';
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
    } else {
    
        int cnt = 31469 - n / 2;
        int cn = 0;
        if (n % 2) cn = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) { 
                    if (i % 2 == 0)
                        mp[i][j] = cnt - cn;
                    else 
                        mp[i][j] = cnt;
                } else {
                    if (i % 2 == 1) {
                        if (j % 2 == 0) {
                            mp[i][j] = 1;
                        } else {
                            mp[i][j] = 0;
                        }
                    } else {
                        if (j % 2 == 0) {
                            mp[i][j] = 0;
                        } else {
                            mp[i][j] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
        
    }


}



int main() {
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }

}