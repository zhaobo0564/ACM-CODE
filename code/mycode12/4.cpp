#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;

string s[N];

string t;

class hash_str {
private:
    string str;
    const long long d = 27;
    const long long MOD = 1234567;
    vector<long long>h, p;
    int n;
public:
    hash_str(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 2);
        p.resize(n + 2);
    }
    hash_str() {}
    void make_hash() {
        h[0] = str[0];
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            h[i] = ((h[i - 1] * d ) % MOD + str[i] ) % MOD;
            p[i] = (p[i - 1] * d ) % MOD;
        }
        p[n] = (p[n - 1] * d) % MOD;
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }
};

int a[N], len[N], base;

int fn[N];
typedef long long ll;
const ll mod = 1234567;

ll dp[1334567];


// ll dfs(int p, int sum) {
//     if (p >  n) {
//         if (sum == base) {
//             //cout << sum << " " << base << endl;
//             return 1;
//         }
//         return 0;
//     }
//     if (dp[p][sum] != -1) return dp[p][sum];
//     ll ans = 0;
//     ans = ans + dfs(p + 1, (sum * fn[len[p]] % mod + a[p]) % mod);
//     ans = ans + dfs(p + 1, sum);
//     return dp[p][sum] = ans;
    
// }

int main() {
    ios::sync_with_stdio(0);
    fn[0] = 1;
    for(int i = 1; i < N; i++) {
        fn[i] = (fn[i - 1] * 27) % mod;
    }
    cin >> n >> t;
    hash_str h(t);
    h.make_hash();
    base = h.get_hash(0, t.length() - 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        len[i] = s[i].length();
        hash_str hs(s[i]);
        hs.make_hash();
        a[i] = hs.get_hash(0, s[i].length() - 1);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < mod; j++) {
          
            
            if (dp[j]) {
                ll cnt = 1ll* j * fn[len[i]] % mod + a[i];
                cnt = cnt % mod;
                cout << cnt << endl;
                dp[cnt] += dp[j]; 
            }
        }
    }
    cout << dp[base] << endl;
    


}