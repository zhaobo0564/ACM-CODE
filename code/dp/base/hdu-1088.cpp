// // dfs+记忆化
// #include<iostream>
// #include<cstring>
// #include<stdio.h>
// using namespace std;
// const int N = 107;

// int mp[N][N], n, m, dp[N][N];

// bool judge(int x, int y) {
//     if (x < 1 || y < 1 || x > n || y > m) {
//         return false;
//     } 
//     return true;
// }

// int dfs(int x, int y) {
//    // cout << x << " " << y << endl;
//     int ans = 0;
//     int f = 0;
//     if (dp[x][y] != -1) return dp[x][y];
//     if (judge(x + 1, y) && mp[x + 1][y] > mp[x][y]) {
//         ans = max(ans, dfs(x + 1, y) + 1);
//     } 
//     if (judge(x - 1, y) && mp[x - 1][y] > mp[x][y]) {
//         ans = max(ans, dfs(x - 1, y) + 1);
//     }
//     if (judge(x, y - 1) && mp[x][y - 1] > mp[x][y]) {
//         ans = max(ans, dfs(x, y - 1) + 1);
//     }
//     if (judge(x, y + 1) && mp[x][y + 1] > mp[x][y]) {
//         ans = max(ans, dfs(x, y + 1) + 1);
//     } 
//     return dp[x][y] = ans;
// }

// int main() {
//     scanf("%d %d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             scanf("%d", &mp[i][j]);
//         }
//     }
//     memset(dp, -1, sizeof(dp));
//     int ans = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             int cnt = dfs(i, j) + 1;
//             ans = max(ans, cnt);
//         }
//     }

//     printf("%d\n", ans);

// }


// 线性dp


#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 107;

int mp[N][N], n, m, dp[N * N];


bool judge(int x, int y, int xx, int yy) {
    if (y == yy) {
        if (abs(x - xx) == 1) {
            return true;
        }
        return false;
    } 
    if (x == xx) {
        if (abs(y - yy) == 1) {
            return true;
        }
        return false;
    }
    return false;
}

struct node {
    int x, y, z;
}p[N * N];

bool cmp(node a, node b) {
    return a.z > b.z;
}

int main() {
    scanf("%d %d", &n, &m);
    int total = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
            p[total].x = i;
            p[total].y = j;
            p[total++].z = mp[i][j];
        }
    }
    sort(p + 1,  p + total, cmp);
    int ans = 0;
    memset(dp, 0 , sizeof(dp));
    for (int i = 1; i < total; i++) {
        
        for (int j = i + 1; j < total; j++) {
            if (p[i].z > p[j].z && judge(p[i].x, p[i].y, p[j].x, p[j].y)) {
                dp[j] = max(dp[j], dp[i] + 1);
                ans = max(ans, dp[j]);
            }
        }
    }
   
    printf("%d\n", ans + 1);
}





