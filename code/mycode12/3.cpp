#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

char s[N];
int main() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    ll ans = 0;
    char last = '0';
    int i;
    for (i = 1; i <= n - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 2] != s[i] && last != s[i]) {
            ans += 1ll*(n - (i + 2)) + 1;
           // cout << ans << endl;

            last = s[i];
            i++;
        } else {
            if (s[i] == last) {
                ans--;
            }
        }
        
    }
    for (; i <= n; i++) {
        if (s[i] == last) {
            ans--;
        }
    }
    cout << ans << endl;

    
}

//a
