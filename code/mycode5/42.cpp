#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

char s[N];

int n, t;

int work(char a, char b) {

    int f = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f == 0 && s[i] == a) {
            ans++;
            f = 1;
        } else if (f == 1 && s[i] == b) {
            ans++;
            f = 0;
        }

    }
    if (f == 1 && a != b) {
        ans--;
    }
    return n - ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", (s + 1));
        n = strlen(s + 1);
        int maxn = n + 100;
        for (char i = '0'; i <= '9'; i++) {
            for (char j = '0'; j <= '9'; j++) {
                maxn = min(maxn, work(i, j));
            }
        }
        printf("%d\n", maxn);

    }
}