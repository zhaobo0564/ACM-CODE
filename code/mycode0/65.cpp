#include<bits/stdc++.h>
using namespace std;
long long mp[100][100], n, a[100][100];

int main(){
    while(~scanf("%lld", &n) && n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%lld", &mp[i][j]);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%lld", &a[i][j]);
            }
        }
        int f = 0, maxn = 0, f1 = 0, f2 = 0, f3= 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][j] == a[i][j]){
                    f++;
                }
                if(mp[i][j] == a[j][n - i + 1]){
                    f1++;
                }
                if(mp[i][j] == a[n - i + 1][n - j + 1]){
                    f2++;
                }
                if(mp[i][j] == a[n -j + 1][i]){
                    f3++;
                }
           

            }
        }
        maxn = max(maxn, max(f, f1));
        maxn = max(maxn, max(f2, f3));
        printf("%d\n", maxn);


        
    }
}