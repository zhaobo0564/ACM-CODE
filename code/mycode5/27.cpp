#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int sum[N][30], n, t, vis[30];

char s[N];

int get(int l, int r, int pos) {
    return sum[r][pos] - sum[l - 1][pos];
}
int minn;

void work(int l, int r, int cnt, int ans) {
    if (l == r) {
        ans +=1 - get(l, l, cnt);
        minn = min(minn, ans);
        return;
    }
    int m = (l + r) / 2;
    int lans = get(l, m, cnt);
    int rans = get(m + 1, r, cnt);
   // cout << lans << " " << rans << endl;
    work(l, m, cnt + 1, ans + ((r - m) - rans));
    work(m + 1, r, cnt + 1, ans + (m - l + 1 - lans));
  
}



int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", (s + 1));
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j < 30; j++) {
                sum[i][j] = 0;
                vis[j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            vis[s[i] - 'a']++;
            for (int j = 0; j < 26; j++) {
                sum[i][j] = vis[j];
            }
        }
        minn = INT_MAX;
        work(1, n, 0, 0);
        

        printf("%d\n", minn);

    }
}