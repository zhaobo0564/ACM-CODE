#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
typedef long long ll;
string s[N];

const ll mod = 998244353;

class hash_str {
private:
    string str;
    const long long d = 238;
    const long long MOD = 1610612741;
    vector<long long>h, p;
    int n;
public:
    hash_str(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 1);
        p.resize(n + 1);
    }
    hash_str() {}
    void make_hash() {
        h[0] = str[0];
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            h[i] = ((h[i - 1] * d ) % MOD + str[i] ) % MOD;
            p[i] = (p[i - 1] * d ) % MOD;
        }
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }

};

class hash_str1 {
private:
    string str;
    const long long d = 32;
    const long long MOD = 1e9 + 7;
    vector<long long>h, p;
    int n;
public:
    hash_str1(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 1);
        p.resize(n + 1);
    }
    hash_str1() {}
    void make_hash() {
        h[0] = str[0];
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            h[i] = ((h[i - 1] * d ) % MOD + str[i] ) % MOD;
            p[i] = (p[i - 1] * d ) % MOD;
        }
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }

};

void get(string x, int next[]) {
    for (int i = 0; i <= x.length(); i++) next[i] = 0;
    int i = 0;
    int k = -1;
    int len = x.length();
    next[i] = -1;
    while (i < len) {
        if (k == -1 || x[i]  == x[k]) {
            next[++i] = ++k;
        } else {
            k = next[k];
        }
    }
}

struct pair_hash{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const{
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};


unordered_map<pair<ll, ll>, ll, pair_hash>mp;
int n, nxt[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        hash_str str(s[i]);
        str.make_hash();
        hash_str1 str1(s[i]);
        str1.make_hash();
        for (int j = 0; j < s[i].length(); j++) {
            mp[{str.get_hash(j, s[i].length() - 1), str1.get_hash(j, s[i].length() - 1)}]++;
        }

    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        hash_str str(s[i]);
        hash_str1 str1(s[i]);
        str.make_hash();
        str1.make_hash();
        get(s[i], nxt);
       
        int len = s[i].length();
        for (int j = len - 1; j >= 0; j--) {
            ll cnt = mp[{str.get_hash(0, j), str1.get_hash(0, j)}];
          
            ans = (ans + cnt % mod * 1ll * (j + 1)% mod * 1ll* (j + 1) % mod) % mod;
            if (nxt[j + 1] <= 0) continue;
            ans = (ans - 1ll * (nxt[j + 1]) * (nxt[j + 1]) * cnt % mod + mod) % mod;
        }

    }
    printf("%lld\n", ans);



}