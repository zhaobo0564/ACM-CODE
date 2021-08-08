#include<bits/stdc++.h>
using namespace std;
char s[1000007];
set<char>q;
int main() {
    int a, x;
    cin >> a >> x;
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        int b = i | a;
        if (b == (i + a)) {
            ans++;
        }
    }
    cout << ans << endl;
}