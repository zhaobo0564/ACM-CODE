#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1610612741;
class hash_str {
private:
    string str;
    const long long d = 238;
    vector<long long>h, p;
    int n;
public:
    hash_str(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 1);
        p.resize(n + 1);
        this->make_hash();
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
        if (r <l ) return 0;
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }

    long long get_p(int l) {
        return p[l];
    }
};

int n;
string s;

int main() {
    cin >> n >> s;
    hash_str hash(s);
    reverse(s.begin(), s.end());
    hash_str ha(s);
  //  cout << s << endl;
    int ans = 0;
    for (int i = 0; i <= n - 1; i++) {
        int len = n + i;
        if (len % 2 == 0) {
            int pos = len / 2 - 1;
            int pos1 = len / 2;
            ll cnt = hash.get_hash(0, pos);
           // cout << "pos " << pos << endl;
            ll cnt1 = ha.get_hash(0, (n - 1 - pos - 1));
            //cout << "l " << 0 <<  " r " << n - 1 - pos - 1 << endl;
            if (i) {
                ll cnt2 = hash.get_hash(0, i - 1);
                //cout << "LL " << 0 << " rr " << i - 1 << endl;
               // cout << "len " << n - 1 - pos << endl;
                cnt1 = cnt2 * hash.get_p(n - 1 - pos) % MOD + cnt1;
                cnt1 %= MOD; 
            }
            if (cnt == cnt1) {
                printf("%d\n", i);
                return 0;
            }
               
        } else {
            int pos = len / 2;
            int pos1 = len / 2;
            ll cnt = hash.get_hash(0, pos);
            //cout << "pos " << pos << endl;
            ll cnt1 = ha.get_hash(0, (n - 1 - pos ));
            //cout << "l = " << 0 << " r = " << n - 1 - pos  << endl;
            if (i) {
                ll cnt2 = hash.get_hash(0, i - 1);
               // cout << "LL " << 0 << " r = " << i - 1 << endl;
             //   cout << "len = " << n  - pos << endl;
                cnt1 = cnt2 * hash.get_p(n  - pos) % MOD + cnt1;
                cnt1 %= MOD; 
            }
           // cout << "cnt= " << cnt << " cnt1 = " << cnt1 << endl;
            if (cnt == cnt1) {
                printf("%d\n", i);
                return 0;
            }

        }
    }
}