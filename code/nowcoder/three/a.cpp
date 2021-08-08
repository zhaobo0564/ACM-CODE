#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;


char s[N];
int q;

int main() {
    scanf("%s", (s + 1));
    scanf("%d", &q);
    int len  = strlen(s + 1);
    int ans = 0;
    while (q--) {
        char op;
        int x;
        scanf(" %c %d", &op, &x);
        if (op == 'M') {
            if (x < 0) {
                x = len + x;
            }
            ans += x;
        } else if (op == 'A') {
            int cnt = x + abs(ans);
            if (cnt > len) {
                cnt = cnt % len;
            }
            
            printf("%c\n", s[cnt]);
        }
        ans = ans % len;
    }
}