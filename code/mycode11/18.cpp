#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, d, s;
int x[200], y[200];

int main() {
    cin >> n >> s >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] < s && y[i] > d) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}