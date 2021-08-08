#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int n;

string s[N];

string t;

class hash_str {
private:
    string str;
    const long long d = 27;
    const long long MOD = 1e9 + 7;
    vector<long long>h, p;
    int n;
public:
    hash_str(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 2);
        p.resize(n + 2);
    }
    void set(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 2);
        p.resize(n + 2);
    }
    hash_str() {}
    void make_hash() {
        h[0] = str[0] - 'a' + 1;
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            h[i] = ((h[i - 1] * d ) % MOD + str[i] - 'a' + 1 ) % MOD;
            p[i] = (p[i - 1] * d ) % MOD;
        }
        p[n] = (p[n - 1] * d) % MOD;
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }

};

long long a[N], base;
int len[N];

int fn[5000007];
typedef long long ll;
const ll mod = 1e9 + 7;
int l[5000007];

vector<int> g;
hash_str h;
void dfs(int p, int limit, ll sum, int L) { 
    // if (L > t.length()) return;
    // if (L && h.get_hash(0, L - 1) != sum) return;
  
    if (p > limit) {
        //cout << "L = " << L << endl;
        l[L]++;
        return;
    }

    if (L + len[p] <= t.length()) {
        if (h.get_hash(0, L + len[p] - 1) == ((sum % mod * fn[len[p]] % mod) % mod + a[p]) % mod)
            dfs(p + 1, limit, ((sum % mod * fn[len[p]] % mod) % mod + a[p]) % mod, L + len[p]);
    }
   
    dfs(p + 1, limit, sum, L);
}
ll ans = 0;

int f[N];

void dfs1(int p, int limit, ll sum, int L) {   
    // if (L > t.length()) return;

    // if (L && h.get_hash(t.length() - L, t.length() - 1) != sum) {
    //     return;

    // }
 
    if (p < limit) {
      
        ans += 1ll*l[t.length() - L];
        return;
    }
    if (L + len[p] <= t.length()) {
        if (h.get_hash(t.length() - L - len[p], t.length() - 1) == ((a[p] % mod * fn[L] % mod) % mod + sum) % mod)
            dfs1(p - 1, limit, ((a[p] % mod * fn[L] % mod) % mod + sum) % mod, L + len[p]); 
    }
    
    dfs1(p - 1, limit, sum, L);
}




int main() {
    ios::sync_with_stdio(0);
    fn[0] = 1;
    for(int i = 1; i < 5000006; i++) {
        fn[i] = (fn[i - 1] * 27) % mod;
    }
    cin >> n >> t;
    int lt = t.length();
    h.set(t);
    h.make_hash();
    base = h.get_hash(0, t.length() - 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        len[i] = s[i].length();
        hash_str hs(s[i]);
        hs.make_hash();
        a[i] = hs.get_hash(0, s[i].length() - 1) % mod;
    }
    dfs(1, n / 2, 0, 0);
    dfs1(n, n / 2 + 1, 0, 0);

    cout << ans << endl;
}
