#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int y; cin >> y;
        if (i % 2 == 0) {
            x -= (y - 1);
        } else {
            x -= y;
        }
    }
    if (x < 0) {
        puts("No");
    } else {
        puts("Yes");
    }
    return 0;
}