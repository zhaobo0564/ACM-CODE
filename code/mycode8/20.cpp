#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

string s;

int n, m;

struct node {
    string name;
    int v;
};
string name, ans;
vector<node> g;

bool cmp(node x, node y) {
    if (x.v == y.v) {
        return x.name < y.name;
    }
    return x.v > y.v;
}

int work() {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ans[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    cin >> s;
    
    for (int i = 1; i <= m; i++) {
        cin >> name;
        cin >> ans;

        g.push_back({name, work()});
    }
    sort(g.begin(), g.end(), cmp);
    cout << g[0].name << endl;
    double res = (double)g[0].v / (double)n;
    res = res * 100;
    printf("%.2f\n", res);
}