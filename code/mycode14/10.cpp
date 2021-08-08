#include<bits/stdc++.h>
using namespace std;

int main() {
    int h = 22, m = 28, s = 45;
 //   cin >> h >> m >> s;
    int ans = h * 3600 +  m * 60 + s;
    int h1 = 24, m1 = 0, s1 = 0;
    int ans1 = h1 * 3600;
    ans1 -= ans;
    ans1 += 6 * 3600 + 24 * 60 + 26;
    cout << ans1 << endl;
    cout << ans1 / 3600 << " ";
    ans1 %= 3600;
    cout << ans1 / 60 << " ";
    cout << ans1 % 60 << endl;

}