#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;


ll ksm(ll a, ll n){
    ll base = 1;
    while(n){
        if(n & 1) base = base * a;
        a = a * a;
        n = n / 2;
    }
    return base;
}

int cnt[20];

vector<ll>g;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    string s = "codeforces";
    for(int i = 1; i <= 10; i++){
        cnt[i] = 1;
    }
    for(ll i = 1; i <= 50; i++){
        g.push_back(ksm(i, 1ll*10));
    }
    int p;
    for(int i = 0; i < g.size(); i++){
        if(k  <= g[i]){
            p = i - 1;
            break;
        }
    }
  //  cout << p << endl;
   

    for(int i = 1; i <= 10; i++){
        cnt[i] += p;
    }
    for(int i = 1; i <= 10; i++){
        cnt[i] += 1;
        ll base = 1;
        for(int j = 1; j <= 10; j++){
            base = base * cnt[j];
        }
        if(base >= k){
            break;
        }
    }
   //int ans = 0;
    for(int i = 1; i <= 10; i++){
        //ans += cnt[i];
        for(int j = 1; j <= cnt[i]; j++){
            cout << s[i - 1];
        }
    }
  //  cout << ans << endl;
    cout << endl;
    

}