#include<bits/stdc++.h>

using namespace std;

int n;
string s;
typedef long long ll;
ll transform(char c) {
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'A'+10;
}

ll work(int n, string str) { 
    ll ans = 0;
    int l=str.length();
    for(int i=0;i<l;i++) {
        ans*=1ll*n;
        ans+=1ll*transform(str[i]);
    }
    return ans;

}
vector<ll> v;
bool gao(ll x) {
    v.clear();
    while (x) {
        v.push_back(x % n);
        x = x / n;
    }
    if (v.size() % 2 == 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != v[v.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    } else {
         for (int i = 0; i < v.size(); i++) {
            if (v[i] != v[v.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
}

string cal() {
    reverse(v.begin(), v.end());
    string a = "";
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 10) {
            a += char('0' + v[i]);
        } else {
            a += char('A' + v[i] % 10);
        }
    }
    return a;
}

int main() {
    cin >> n >> s;
    for (int i = 1; i <= 30; i++) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        ll ans = work(n, s) + work(n, s1);
        if (gao(ans)) {
            cout << "STEP=" << i << endl;
            return 0;
        }
        s = cal();
      //  cout << s << endl;
    }
    cout << "Impossible!\n";

    return 0;
    
}