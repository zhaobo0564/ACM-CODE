#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x, y; scanf("%d %d %d",&n, &x, &y);
        if (n == 1) {
            cout << min(x, y) << endl;
            continue;
        }
        while (x != y) {
            if (x > y) {
                x = (x + (n - 2)) / n;
            } else {
                y = (y + (n - 2)) / n;
            }
           // cout << x << " " << y << endl;
        }
        cout << x << endl;
    }
}