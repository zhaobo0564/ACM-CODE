#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
char s[N];
int vis[200];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        vis[s[i]]++;
    }
    int f = 0, ans = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        if (vis[i] % 2 == 0) {
            vis[i] = 0;
        } else {
            if (f == 0) {
                vis[i] = 0;
                f = 1;
            }
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (vis[i] % 2) {
            ans++;
        }
    }
    printf("%d\n", ans);

}