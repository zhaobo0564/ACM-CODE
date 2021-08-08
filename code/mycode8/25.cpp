#include<stdio.h>
#include<iostream>
#include<vector>
#include <math.h>
#include<algorithm>
using namespace std;
const int N = 207;

int a[N], b[N], n, m;

struct node {
    int x, y;
}dp[N][22][807];

int pre[N][22][807];

int main() {
    int ca = 1;
    while(~scanf("%d %d", &n, &m) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &a[i], &b[i]);
        }
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int z = 0; z <= 800; z++) {
                    dp[i][j][z].x = -1e8;
                    dp[i][j][z].y = -1e8;
                    pre[i][j][z] = 0;
                }
            }
        }
        int base = 400;

        dp[0][0][base].x = dp[0][0][base].y = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {
                for (int z = 0; z <= 800; z++) {
                    dp[i][j][z] = dp[i - 1][j][z];
                    pre[i][j][z] = -1;
                }
            }
            for (int j = 1; j <= min(i, m); j++) {
                for (int z = 0; z <= 800; z++) {
                    int cnta = dp[i - 1][j - 1][z].x + a[i];
                    int cntb = dp[i - 1][j - 1][z].y + b[i];

                    

                    int sum = dp[i][j][cnta  - cntb + base].x + dp[i][j][cnta  - cntb + base].y;
                 

                    if (sum < cnta + cntb) {
                        dp[i][j][cnta - cntb + base].x = cnta;
                        dp[i][j][cnta - cntb + base].y = cntb;
                        pre[i][j][cnta - cntb + base] = 1;
                    }
                 }   
            }

            
        }

      //  cout << dp[1][1][base].x << endl;

        int suma = 0 , sumb = 0, z = 1000, mx = 0;;

        //cout << dp[n - 1][3][12].x << " " << dp[n - 1][3][12].y<< endl;
 
        for (int i = 0; i <= 400; i++) {
           
            //cout << dp[n][m][base + i].x << endl;
            if (dp[n][m][base + i].x >= 0) {
                
                suma = dp[n][m][i + base].x;
                sumb = dp[n][m][i + base].y;
            
                z = i;
                break;
            }
        }

         for (int i = 0; i <= 400; i++) {
           
            if (i == z && dp[n][m][base - i].x >= 0) {
                
                if (dp[n][m][base - i].x + dp[n][m][base - i].y > suma + sumb) {
                    suma = dp[n][m][base - i].x;
                    sumb = dp[n][m][base - i].y;
                    z = -i;
                    break;
                }
            } else if (i < z && dp[n][m][base - i].x >= 0) {
                suma = dp[n][m][base - i].x;
                sumb = dp[n][m][base - i].y;
            
                z = -i;
                break;
            }
        }


        int x = n, y = m;

        vector<int> ans;
        printf("Jury #%d\n", ca++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", suma, sumb);
     
        while (1) {
            if (pre[x][y][base + z] == 1) {
                ans.push_back(x);
                int cnta = dp[x][y][z + base].x - a[x];
                int cntb = dp[x][y][z + base].y - b[x];
                z = cnta - cntb;
                x--;
                y--;
                
            } else {
                x--;
            }
            if (x == 0 || y == 0) {
                break;
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << endl << endl;



        
    }
}

/*
7 4
18 16
6 17
2 11
10 9
2 4
17 4
1 13

*/