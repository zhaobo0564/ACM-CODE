#include<bits/stdc++.h>

using namespace std;

long long work(int n, int k) {
    __int128_t res = 1;
    // for (int i = 1; i <= k; i++) {
    //     res = res * (n - k + i);
    //     res = res / i;
    //     if (res >= 1e18) {
    //         return 1e18;
    //     }
    // }
    return res;
} 

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("%lld\n", work(a, b));
    }
}