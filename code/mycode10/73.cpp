#include<bits/stdc++.h>

using namespace std;
const int N = 2e7 + 7;

char s[N];
int k;

bool vis[N];

deque<int> q[11];

int main() {
    scanf("%s %d", (s + 1), &k);
    int n = strlen(s + 1);
    if (k == n) {
        puts("0");
        return 0;
    }

    for (int i = 1; i <= k + 1; i++) {
        q[s[i] - '0'].push_back(i);
    }

    int cnt = k + 2;
    int ans = 0, last = 1;
    while (1) {
        int pos = -1;
        for (int i = 0; i <= 9; i++) {
            if (q[i].size()) {
                pos = q[i].front();
                ans += pos - last;
                last = pos + 1;
                vis[pos] = 1;
                break;
            }
        }
        
        if (k - ans == n - pos) {
            cnt = n + 1;
            break;
        }
        int f = 0;
        for (int i = 0; i <= 9; i++) {
            while (q[i].size() && q[i].front() <= pos) {
                q[i].pop_front();
            }
            if (q[i].size()) {
                f = 1;
            }
        }
        if (f == 0) break;
        if (cnt <= n) {
            q[s[cnt] - '0'].push_back(cnt);
            cnt++;
        }
    }
    int f = 0;
    for (int i = 1; i < cnt; i++) {
        if (vis[i]) {
            if (f == 0 && s[i] == '0') {

            } else {
                f = 1;
                printf("%c", s[i]);
            }
            
        }
    }
    for (int i = cnt; i <= n; i++) {
        if (f == 0 && s[i] == '0') {

        } else {
            f = 1;
            printf("%c", s[i]);
        }
    }
    if (f == 0) {
        printf("0");
    }
    puts("");

}