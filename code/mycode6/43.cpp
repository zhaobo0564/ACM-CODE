#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

typedef long long ll;

ll mp[N][N], n, m, qq, minn[N][N], maxn[N][N], cnt[N][N];
 deque<ll>q;
 
void work(ll x, ll y) {
	// memset(maxn, 0, sizeof(maxn));
	// memset(minn, 0, sizeof(minn));
	for (int i = 1; i <= n; i++) {
        q.clear();
        for (int j = 1; j <= m; j++) {
            while (!q.empty() && mp[i][q.back()] >= mp[i][j]) {
                q.pop_back();
            }
            q.push_back(j);
            while(!q.empty() && q.front() <= j - y) {
                q.pop_front();
            }
            maxn[i][j] = mp[i][q.front()];
        
            //cout << -maxn[i][j] << " ";
        }
      //  cout << endl;
    }


    for (int i = 1; i <= m; i++) {
        q.clear();
        for (int j = 1; j <= n; j++) {
            while (!q.empty() && maxn[q.back()][i] >= maxn[j][i]) {
                q.pop_back();
            }
            q.push_back(j);
            while(!q.empty() && q.front() <= j - x) {
                q.pop_front();
            }
            minn[j][i] = maxn[q.front()][i];
        }
    }
}

ll solve(ll x, ll y) {
	ll ans = 1e18;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cout << minn[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
	for (int i = x; i <= n; i++) {
		for (int j = y; j <= m; j++) {
			ll cat = cnt[i][j] - cnt[i][j - y] - cnt[i - x][j] + cnt[i - x][j - y];
            ll cn = cat + (1ll*minn[i][j] * x * y);
             //if (cn < 0) continue;
             cout << minn[i][j] << " " ;
             if (minn[i][j] == 16) {
                 cout << endl;
                 int aa = 10000000;
                 for (int ii = i - x + 1 + 2; ii <= i; ii++) {
                     for (int jj = j - y + 1 ; jj <= j; jj++) {
                         cout << mp[ii][jj] << ' ';
                         aa = min(1ll*aa, mp[ii][jj]);
                     }
                     cout << endl;
                 }
                 cout << aa << endl;
                return 0;
             }
             

			ans = min(ans, cn);
            // if (cn < 0) {
            //     cout << "YES\n";
            //     cout << cat << " " << (1ll*minn[i][j] ) << endl;
            // }
		}
        cout << endl;
	}
	return ans;
}
 
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &mp[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] + mp[i][j] - cnt[i - 1][j - 1];
		}
	}
	
	scanf("%d", &qq);
	while (qq--) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		work(x, y);
    
		printf("%lld\n", solve(x, y));
		
	}
   

}