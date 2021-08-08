#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int tree[40 * N], ls[40 * N], rs[40 * N];
#define m (l + r) / 2
#define lson ls[node]
#define rson rs[node]

int top = 1;
int main() {
    int rt = 0;
    int t; scanf("%d", &t);

    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        int cnt = 0, ans;
        x = n / x;
        int r;
        for (int i = 1; i <= n; i = r + 1) {
            ans =  n / i;
            cnt++;
            if (ans == x) {
                break;
            }
            if (cnt == 40000) break;
            r = n / (n / i);
        }
        cout << ans << endl;
        if (ans == x) {
            printf("%d\n", cnt);
        } else {
            printf("%d\n", cnt + ans - x);
        }
        
    } 

   

}