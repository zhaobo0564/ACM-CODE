#include<bits/stdc++.h>

using namespace std;

int n, m;

const int N = 1e6 + 7;

vector<int> mp[N];

int get_sum(int x, int y) {
    if (x + 1 > n || y + 1 > m || x < 1 || y < 1) {
        return 0;
    }
    return mp[x][y] + mp[x + 1][y] + mp[x + 1][y] + mp[x + 1][y + 1];
}

int work(int x, int y) {
    int sum = 0;
    if (get_sum(x - 1, y - 1) % 2) {
        sum++;
    } 
    if (get_sum(x, y - 1) % 2) {
        sum++;
    }
    if (get_sum(x - 1, y ) % 2) {
        sum++;
    }
    if (get_sum(x , y) % 2) {
        sum++;
    }
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        mp[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            int x; scanf("%1d", &x);
            mp[i].push_back(x);
        }
    }
    if (n >= 4 && m >= 4){

    } else {
        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int ans = -1, x, y;
                if (get_sum(i, j) % 2) continue;
                mp[i][j] ^= 1;
                if (work(i, j) > ans) {
                    ans = work(i, j);
                    x = i, y = j;
                }
                mp[i][j] ^= 1;
                mp[i + 1][j] ^= 1;
                if (work(i + 1, j) > ans) {
                    ans = work(i + 1, j);
                    x = i + 1, y = j;
                } 
                mp[i + 1][j] ^= 1;
                mp[i][j + 1] ^= 1;
                if (work(i, j + 1) > ans) {
                    ans = work(i, j + 1);
                    x = i, y = j + 1;
                }
                mp[i][j + 1] ^= 1;
                mp[i + 1][j + 1] ^= 1;
                if (work(i + 1, j + 1) > ans) {
                    ans = work(i + 1, j + 1);
                    x = i + 1, y = j + 1;
                }
                mp[i + 1][j + 1] ^= 1;
                if (ans > -1) {
                    mp[x][y] ^= 1;
                    cout << x << " " << y << endl; 
                }
            }
            
            

        }
        printf("%d\n", res);
    }

}