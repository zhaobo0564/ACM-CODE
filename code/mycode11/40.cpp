#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 0) {
                if (j % 2) {
                    printf("1");
                } else {
                    printf("0");
                }
            } else {
                if (j % 2) {
                    printf("0");
                } else {
                    printf("1");
                }
            }
        }
        puts("");
    }
}