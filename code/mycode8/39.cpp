#include<bits/stdc++.h>
using namespace std;

const int N = 50;

int A[N], n;

vector<int>a, b;

int dfs(int p, int sum, int ct) {
    
    if (sum == n / 2 && ct == n / 2) {
        return 1;
    }
    if (sum == ct && sum) {
        if (a[sum - 1] != b[sum - 1]) {
            return 0;
        }
    } else if (sum > ct && ct) {
        if (a[ct - 1] != b[ct - 1]) {
            return 0;
        }
    } else if (ct > sum && sum) {
        if (a[sum - 1] != b[sum - 1]) {
            return 0;
        }
    }
    if ( p > n || sum + (n - p + 1) < n / 2 || ct + (n - p + 1) < n / 2) return 0;

    if (sum < n / 2) {
        a.push_back(A[p]); 
        int ans = dfs(p + 1, sum + 1, ct);
        if (ans) return 1;
        a.pop_back();
    }
    
    if (ct < n / 2) {
        b.push_back(A[p]);
        int f = dfs(p + 1, sum, ct + 1);
        if (f) return 1;
        b.pop_back();
    }
    return 0;

}

int main() {
   // srand(time(0));
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
          //  A[i] = rand()%n + 1;
        }
        a.clear(), b.clear();
        if (dfs(1, 0, 0)) {
            puts("Frederica Bernkastel");
        } else {
            puts("Furude Rika");
        }
    }
}