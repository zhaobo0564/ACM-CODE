#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[4];

int main() {
    cin >> a[1] >> a[2] >> a[3];
    if (a[1] + a[2] == 2 * a[3] || a[1] + a[3] == 2 * a[2] || a[3] + a[2] == 2 * a[1]) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}