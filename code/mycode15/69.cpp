#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = b - a + 1;
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}