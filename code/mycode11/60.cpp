#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;




int prime[N], vis[N], top = 1, cnt[N];

void init(int n) {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break; 
        }
    }

    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 1; j < top; j++) {
            if (vis[x] == 0 || prime[j] > x) {
                break;
            }
            if (x % prime[j] == 0) {
                while (x % prime[j] == 0) {
                    cnt[prime[j]]++;
                    x = x / prime[j];
                }

            }
        }
        if (x > 1) {
            cnt[x]++;
        }
    }
}


int main() {
   
    int n;
    cin >> n;
    init(n);

    for (int i = 2; i <= n; i++) {
        if (cnt[i]) {
            cout << i <<' ' << cnt[i] << endl;
        }
    }

}