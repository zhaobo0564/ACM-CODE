#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        ll a, x;
        scanf("%lld %lld", &a, &x);
        if (a >= 10) {
            if (x == 9 || x == 3) {
                puts("T");
            } else {
                puts("F");
            }
        } 
    }
}