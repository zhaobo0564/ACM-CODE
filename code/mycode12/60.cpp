#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

string a, b;

typedef long long ll;
ll transform(char c) {
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'A'+10;
}

ll work(int n, string str) { // n是多少进制str是n进制的数
    ll ans = 0;
    int l=str.length();
    for(int i=0;i<l;i++) {
        ans*=1ll*n;
        ans+=1ll*transform(str[i]);
    }
    return ans;

}

void solve() {
    cin >> a >> b;
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}