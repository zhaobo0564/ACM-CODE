#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], b[N], n;

int vis[N * 30];

int cnt[N];

int main() {
   // srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = rand() % n + 1;
        cnt[a[i]] = 1;
    }
    if (cnt[1] == 0) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2;; i++) {
        if (cnt[i] == 0) {
            int f = 0;
            for (int j = 1; j <= n; j++) {
                if (__gcd(a[j], i) != 1) {
                    f = 1;
                    break;
                }
            }
            if (f == 0){
                cout << i << endl;
                return 0;
            }
        }
    }
}
