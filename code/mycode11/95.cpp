#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e5 + 7;
string s, t;

class hash_str {
private:
    string str;
    const long long d = 27;
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
        p[n] = p[n - 1] * d % MOD;
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }
    long long  get(ll x, ll y, int pos) {
    //    cout << "x " << x << " " << p[pos] << " " << y << endl;
        return (x * p[pos] % MOD + y) % MOD;
    }
};

ll sums[N], sumt[N];



int main() {
    ios::sync_with_stdio(0);
    cin >> s >> t;
    hash_str hashs(s);
    hashs.make_hash();
    hash_str hasht(t);
    hasht.make_hash();

    for (int i = 0; i < s.length(); i++) {
        sums[i] = hashs.get_hash(0, i);
    }
    for (int i = 0; i < t.length(); i++) {
        sumt[i] = hasht.get_hash(0, i);
    }

    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ll cnt = sums[i];
        int l = 1, r = t.length() - i - 1;
        int res = 0;
      //  cout << "cnt " << cnt << " " << i << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll cn = hashs.get_hash(0, mid - 1);
         //   cout << "cn " << cn << endl;
            cn = hashs.get(cnt, cn, mid);

          //  cout << "Mid = " << mid << endl;
          //  cout << "cn " << cn << " len " << mid + i << " " << sumt[mid + i] << endl;
            if (cn == sumt[mid + i]) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
      //  cout << res << endl;
        ans += 1ll*res;
    }
    cout << ans << endl;



    

    


}