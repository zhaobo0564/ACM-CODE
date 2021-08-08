#include<bits/stdc++.h>
using namespace std;

int main() {
    int h = 60405, up = 105, down = 35;
    int ans = 0, now = 0;
    while (1) {
        ans++;
        now += up;
        if (now >= h) break;
        now -= down;
    }
    cout << ans << endl;
}