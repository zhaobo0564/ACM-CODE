#include<bits/stdc++.h>
using namespace std;

int t;
typedef long long ll;
ll n, m;

string a[200];

ll work(string str){
    ll base = 0, res = 1;
    reverse(str.begin(), str.end());
    for(int i = 0; i < m; i++){
        if(str[i] == '1'){
            base += res;
        }
        res *= 2;
    }
    return base;
}

int gao(ll x, vector<ll> &g){
    for(int i = 0; i < g.size(); i++){
        if(x == g[i]){
            return -1;
        }
        if(g[i] > x){
            return i;
        }
    }
    return 0;
}


int main(){
    scanf("%d", &t);
    while(t--){
        vector<ll>g;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            g.push_back(work(a[i]));
        }
        sort(g.begin(), g.end());
        ll cnt = 1 << n;
        cnt--;
        ll mid = (cnt - n) / 2;
        ll m = cnt / 2;
        ll ans = -1;
        for(ll i = max(1ll * 0, m - 10000); i <= min(cnt, cnt + 10000); i++){
           int cn = gao(i, g);
           if(cn == -1) continue;
           ll res = i - cn;
           cout << i << " " << cn << endl;
           if(res == mid){
               ans = res;
               break;
           }
        }
        cout << ans << endl;


       

    }
}