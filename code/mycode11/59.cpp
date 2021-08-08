#include<bits/stdc++.h>

using namespace std;

const int N = 500000 + 7;

int prime[N],vis[N],top=1;
int ans = 0;

void Prime(){
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int st[N * 4];

vector<int> v;

int main() {
    Prime();
    int l, r;
    while (cin >> l >> r) {
        memset(st, 0, sizeof st);
        v.clear();
        for (int i = 1; i < top; i++) {
            int begin = l / prime[i];
            int end = r / prime[i];
            //cout << begin << " " << end << endl;
            for (int j = max(2, begin); j <= end ; j++) {
                int pos = j * prime[i];
                st[pos - l] = 1;
            }
        }

        for (long long i = max(2, l); i <= r; i++) {
            if (st[i - l] == 0) {
                v.push_back(i);
            }
        }
        if (v.size() < 2) {
            puts("There are no adjacent primes.");
        } else {
            int minn = INT_MAX;
            int maxn = 0;
            int l1, r1;
            for (int i = 1; i < v.size(); i++) {
                if (minn > v[i] - v[i - 1]) {
                    minn = v[i] - v[i - 1];
                    l = v[i - 1];
                    r = v[i];
                }
                if (maxn < v[i] - v[i - 1]) {
                    maxn = v[i] - v[i - 1];
                    l1 = v[i - 1];
                    r1 = v[i];
                }
            }

            printf("%d,%d are closest, %d,%d are most distant.\n", l, r, l1, r1);
        }
    }
}