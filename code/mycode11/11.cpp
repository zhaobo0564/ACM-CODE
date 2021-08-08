#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n == 1) {
            puts("ma la se mi no.1!");
        } else {
            if (k >= n) {
                puts("yo xi no forever!");
            } else {
                if (((n - 1) % (k + 1)) != 0) {
                    puts("yo xi no forever!");
                } else {
                    puts("ma la se mi no.1!");
                }
            }
        }
    }
}