#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 7;
int isnot[N];
vector<int>G[N];
void getys(){
    for(int i=2;i<N;i++){
        if(!isnot[i]) {
            for (int j = i; j < N; j += i) {
                isnot[j] = true;
                int cnt = j;
                while (cnt % i == 0) {
                    G[j].push_back(i);
                    cnt = cnt / i;
                }
                
            }
        }
    }
}

unordered_map<int, int>vis;

int main() {
    getys();

    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        vis.clear();
        vector<int> v;
        for (int i: G[a]) {
            vis[i]++;
            v.push_back(i);
        }
        for (int j: G[b]){
            vis[j]++;
            v.push_back(j);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        ll ans = 1;
        for (int i: v) {
            ans = ans * (vis[i] + 1);
        }
        cout << ans << endl;
    }
}