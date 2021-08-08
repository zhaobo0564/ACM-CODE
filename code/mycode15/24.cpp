#include<bits/stdc++.h>
using namespace std;

vector<pair<int, string> > g;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string name; 
        int x;
        cin >> name >> x;
        g.push_back({x, name});
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    cout << g[1].second << endl;
    return 0;
}