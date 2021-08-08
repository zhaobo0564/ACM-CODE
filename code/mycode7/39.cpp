#include<bits/stdc++.h>
using namespace std;
int mp[30][40], m, k;

typedef long long ll;

ll dp[40][10];

bool judge(int x, int y, int pos) {
    for (int i = 0; i < 3; i++) {
        if (((x & (1 << i)) == 0) && ((y & (1 << i)) == 0)) {
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (mp[i + 1][pos] == 1 && ((x & (1 << i)) == 0)) {
            return false;
        }
        if (mp[i + 1][pos] && ((y &(1 << i))) ) {
            return false;
        } 
    }

    return true;
    
}

int main() {
    scanf("%d %d", &m, &k);
    for (int i = 1; i <= k; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        mp[(int)ceil(y)][(int)ceil(x)] = 1;
    }
    dp[0][7] = 1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 8; j++) {
            for (int z = 0; z < 8; z++) {
                
                if (!judge(j, z, i)) {
                    
                    continue;
                } else {
                    int now = j ^ z;
                    int x = 1;
                    if (now == 0) {
                     //   cout << "now " << now << " z " << z << endl;
                        if (mp[1][i] == 0 && mp[2][i] == 0 &&mp[3][i] == 0) {
                            x = 3;
                        } else if (mp[1][i] == 0 && mp[2][i] == 0) {
                            x = 2;
                        } else if (mp[2][i] == 0 && mp[3][i] == 0) {
                            x = 2;
                        } else {
                            x = 1;
                        }
                    } else if (now == 4) {
                        if (mp[1][i] == 0 && mp[2][i] == 0) {
                            x = 2;
                        } else {
                            x = 1;
                        }
                    } else if (now == 1) {
                        if (mp[2][i] == 0 && mp[3][i] == 0) {
                            x = 2;
                        } else {
                            x = 1;
                        }
                    } else {
                        x = 1;
                    }

                    dp[i][z] += dp[i - 1][j] * x;
                  
                }
            }
        }
    }
    cout << dp[m][7] << endl;
}
