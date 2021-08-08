#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 200000;
int limit = 50000;

int  a[N], cn[N], bn[N];
int cnt[N];

int main() {
    
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        int f = 0;
        for (int j = 2; j * j <= i; j++) {
            if ((i / j) * j == i) {
                f = 1;
            }
        }
        if (f == 0) {
            cnt[++count] = i;
        }
    }
    int t; scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++) {
        int n; scanf("%d", &n);
        int aa = 0, b = 0, c = 0, ans = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
    
        for (int i = 1; i <= n; i++) {
            int j = i;
            bn[j] = cn[j] = 0;
            if (a[j] == 1) continue;
            int cat = a[j];
            while(1) {
                if (cat % 2) break;
                bn[j]++;
                cat >>= 1;
            }
            for (int z = 2; cnt[z] <= sqrt(a[j] + 1); z++) {
                while (1) {
                    if (cat % cnt[z]) break;
                    cat = cat / cnt[z];
                    cn[j]++;
                }
            }
            if (cat >= 2) cn[j]++;
            else {

            }
            if (!bn[i] ) {
                if (!cn[i])
                    a[i] = 0;
            } else {

            }
            if (!cn[i] ) {
                if ((bn[i] + cn[i]) == 1)
                    a[i] = 1;
            } else {
                a[i] = cn[i];
                if (bn[i]) a[i]++; 
            }
            ans = ans ^ a[i];
        }
        if (ans == 0) {
            puts("L");
        } else {
            puts("W");
        }
    }
}