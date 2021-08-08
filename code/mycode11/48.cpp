#include<bits/stdc++.h>
using namespace std;

const int N = 50007;

int n, w[N], s[N];
typedef long long ll;

vector<pair<int , int> >v;

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.first > y.first;
}

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> s[i];
        v.push_back({w[i] + s[i], i});
        sum += w[i];
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        sum -= w[v[i].second];
       // cout << sum << endl;
        ans = max(ans, sum - s[v[i].second]);
    }
    cout << ans << endl;


}