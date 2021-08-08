#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
vector<int>G[N];
ll ans = 0;
int isnot[N];
void getys(){
    for(int i=2;i<N;i++){
        if(!isnot[i]) {
            for (int j = i; j < N; j += i) {
                isnot[j] = true;
                G[j].push_back(i);
            }
        }
    }
}

void work(int x) {
    vector<int> v;
    int y = x;
    for (int i: G[x]) {
        while (y % i == 0) {
            v.push_back(i);
            y = y / i;
        }
    }
    sort(v.begin(), v.end());
    ll base = 0;
    for (int i: v) {
        base = base * 10 + i;
        base = base % mod;
    }
    ans = (ans + base) % mod;
}

int main() {
    getys();

    while (1) {
        int n; cin >> n;
        for (int i = 2; i <= n; i++) {
            work(i);
        }
        cout << ans << endl;
        ans = 0;
    }
}
