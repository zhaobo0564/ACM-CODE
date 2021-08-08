#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, a[N], t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] > a[i - 1]) {
                
            } else {
                f = 1;
            }
        }
        if (!f) {
            puts("0");
        } else {
            int i = 1;
            while(a[i] == i)i++;
            int j = n;
            while(a[j] == j)j--;
            f = 0;
            for(; i <= j; i++) {
                if(a[i] == i) {
                    f = 1;
                }
            }
            if (f) puts("2");
            else puts("1");
        }


    }
}

