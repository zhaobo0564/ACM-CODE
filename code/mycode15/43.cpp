#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

int n, a[N], k;
int fn[100];
map<int, int> vis;

int sum[N];
int low_bit(int x) {
    return x & -x;
}

void add(int pos, int v) {
    while (pos <= n) {
        sum[pos] += v;
        pos += low_bit(pos);
    }
}

int ask(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += sum[pos];
        pos -= low_bit(pos);
    }
    return ans;
}

vector<int> g;

int main() {
    fn[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == k) {
            g.push_back(i);
        }
        vis[a[i]]++;
    }
    int ans = 0, sum = 0;
    for (int i = 0; i < g.size(); i++) {
        int pos = 0;
        for (int j = 0; j <= 20; j++) {
            if (fn[j] > g[i]) {
                pos = j;
                break;
            }
        }
        pos--;
    }



}